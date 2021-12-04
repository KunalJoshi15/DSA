#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;
	// each value has the attribute which has the particular value as true or false.
	Node(char ch){
		data = ch;
		isTerminal = false;
	}
};

class Trie{
public:
	Node *root;

	Trie(){
		root = new Node('\0');
	}

	void insert(string node){
		// this particular temp node is used for the iteration as per our requirement.
		Node *temp = root;
		for(char ch:word){
			// if the particular child is not present. in the map then we insert it,
			if(temp->m.count(ch)==0){
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
		// this means that the particlar node is a terminal node.
		temp->isTerminal = true;
	}

	bool search(string word){
		Node *temp =  root;
		for(char ch:word){
			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];
		}
		return temp->isTerminal;
	}
};

int main()
{
	string words[] = {"apple","ape","no","news","not","never"};
	Trie t;

	for(string w:words){
		t.insert(w);
	}
	int q;
	cin>>q;
	string search_word;
	while(q--){
		cin>>search_word;
		if(t.search(search_word)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}