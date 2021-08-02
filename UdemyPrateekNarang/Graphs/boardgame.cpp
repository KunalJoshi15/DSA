#include<bits/stdc++.h>

using namespace std;
/*
Here we are given the list of words and a board we need to indentify all those words which can be formed in the board using these words.
LETS to move gradually to better solution.
in case of the back tracking solution we need to find all the words which can be formed.
Backtracking is a words solution.

Using the list of the strings which is provided to us we can guide our search space. THis means that we will be increasing our search space as per the requirement.
We will create a trie for all the words which are provided to us.

We don't have to go to all the directions.
*/
#define M 3
#define N 4

class Node{
public:
	char s;
	unordered_map<char,Node*> children;
	// This is used for getting all the words in a particular node.
	string word;
	bool isTerminal;

	Node(char s){
		this->s = s;
		isTerminal = false;
		word = "";
	}
};

class Trie{
public:
	Node *root;

	Trie(){
		root = new Node('\0');
	}
	// Here we have added the words to the trie. we will be creating a root node.
	void addWord(string word){
		Node *temp = root;
		for(auto ch:word){
			if(temp->children.count(ch)==0){
				// if we get inside this if condition then we can simply say that the character is not present in the trie node.
				temp->children[ch] = new Node(ch);
			}
			// After adding the node then we will be simply adding it to the children.
			temp = temp->children[ch];
		}
		temp->isTerminal = true;
		temp->word = word;
	}
};
// MAIN ALGORITHM WHICH IS 8WAY DFS and a trie guided search.
void dfs(char board[M][N],Node *node,int i,int j,bool visited[][N], unordered_set<string> &output)
{
	// base case
	char ch = board[i][j];
	if(node->children.count(ch)==0){
		return;
	} 
	// If for some particular node character is not present as the children then we can simply return.

	// Otherwise trie contains this node.
	visited[i][j] = true;
	node = node->children[ch];

	if(node->isTerminal){
		output.insert(node->word);
	}	
	// EXPLORE the neighbours.
	int dx[] = {0, 1 , 1 ,1, 0, -1, -1,-1};
	int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};
	// int dx[] = {0,1,1,1,0,-1,-1,-1};
	// int dy[] = {-1,-1,0,1,1,1,0,-1};

	for(int k=0;k<8;k++){
		int ni = i+dx[k];
		int nj = j+dy[k];

		// Check whether the indexes are within the boundary or not.
		if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
			dfs(board,node,ni,nj,visited,output);
		}
	}

	// Last Step. When we are going back we will make the ndoes as unvisited.
	visited[i][j] = false;
	return;
}


int main()
{
	string words[] = {"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};

	char boggle[M][N] = {
		{'S','E','R','T'},
		{'U','N','K','S'},
		{'T','C','A','T'}
	};

	// Construct a trie
	Trie t;

	for(auto w:words){
		t.addWord(w);
	}

	//Take the container to store words that are formed in the dfs search.
	unordered_set<string> output;

	// 3. Step 8-way dfs seach.
	bool visited[M][N] = {0};
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			dfs(boggle,t.root,i,j,visited,output);
		}
	}
	for(auto p:output){
		cout<<p<<endl;
	}
	return 0;
}