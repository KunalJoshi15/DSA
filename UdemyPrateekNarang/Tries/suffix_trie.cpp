#include<bits/stdc++.h>

using namespace std;

/*
Suffix trie is the one which has all the suffixes present in the trie.
*/
class Node{
	char key;
	unordered_map<char,Node*> m;
	bool isTerminal;
	Node(char d){
		key = d;
		isTerminal = false;
	}
};

class Trie{
	Node *root;
	Trie(){
		root = new Node('\0');
	}

	void insert_helper(string s){
		Node *temp=root;
		for(char ch:s){
			if(temp->m.count(ch)==m.end()){
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
		// At last we can making it as a terminal so that we can check whether the value is present in the trie or not.
		temp->isTerminal = true;
	}

	bool search(string s){
		for(char ch:s){
			Node *temp = root;
			if(temp->m.count(ch)==m.end()){
				return false;
			}
			temp = temp->m[ch];
		}
		return temp->isTerminal;
	}

	void insert(string s){
		for(int i=0;s[i]!='\0';i++){
			// Insert helper function will create the suffix trie as per our requirement.
			insert_helper(s.substr(i));
		}
	}
};