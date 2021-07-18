#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;
	Node(char d){
		data=d;
		isTerminal=false;
	}
};

class Trie{
public:
	Node *root;
	Trie(){
		root = new Node('\0');
	}

	void insert(string s){
		Node *temp = root;
		for(char ch:s){
			if(temp->m.count(ch)==0){
				Node *n = new Node(ch);
				temp->m[ch]=n;
			}
			temp = temp->m[ch];
		}
		temp->isTerminal=true;
	}

};

void searchHelper(Trie t,string document,int i,unordered_map<string,bool> &m){
	// here we will be checking whether there is a function which will be having a particular value as per our need.
	Node *temp = t.root;

	for(int j=i;j<document.length();j++){
		char ch = document[j];
		if(temp->m.count(ch)==0){
			return;
		}
		temp = temp->m[ch];
		if(temp->isTerminal){
			string out = document.substr(i,j-i+1);
			m[out]=true;
		}
	}
	return;
}

void documentSearch(string document,vector<string> &words){
	// We have created a trie in which all the words have been inserted.
	Trie t;
	for(auto w:words){
		t.insert(w);
	}
	// 2. Searching Helper Function.
	// Here we will even be creating an unordered map in order to store the values for a partiuclar function which is present.
	unordered_map<string,bool> jp;
	for(int i=0;i<document.length();i++){
		searchHelper(t,document,i,jp);
	}
	// 3. Here we can check which are the words which are marked as true in the hashmap.
	for(auto w:words){
		if(jp[w]){
			cout<<w<<" :True"<<endl;
		}
		else{
			cout<<w<<" :False"<<endl;
		}
	}	
}

int main()
{
	string document="little cute cat loves to code in c++,java & python";
	vector<string> words = {"cute cat","ttle","cat","quick","big"};
	// In case of the trie implementation we will be inserting the words that we have into the trie. one by one. O(DW+NW) this will be the time 
	//Complexity of the approach.
	documentSearch(document,words);
}