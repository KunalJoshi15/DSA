#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	string name;
	list<string> nbrs;

	Node(string name){
		this->name = name;
	}
};

class Graph{
	//All nodes
	// We will be having a hashmap with the values.
	// Each of the string will be connected to the other node. Here we will be simply using the vectir if cities vector to push the values.
	unordered_map<string,Node*> m;
public:
	Graph(vector<string> cities){
		for(auto city:cities){
			m[city] = new Node(city);
		}
	}

	void addEdge(string a,string b,bool undir=false){
		m[a]->nbrs.push_back(b);
		if(undir){
			m[b]->nbrs.push_back(a);
		}	
	}

	void printGraph(){
		// Here in the citypair there will be two values one is the stringa other is the node.
		for(auto cityPair:m){
			cout<<cityPair.first<<"->";
			for(auto m:cityPair.second->nbrs){
				cout<<m<<"->";
			}
			cout<<endl;
		}
	}
};

int main()
{
	vector<string> m = {"Almora","Champawat","Kausani","Dehradun","Haldwani"};
	Graph g(m);
	g.addEdge("Almora","Champawat");
	g.addEdge("Kausani","Dehradun");
	g.addEdge("Dehradun","Haldwani",true);
	g.addEdge("Haldwani","Almora",true);
	g.printGraph();
}