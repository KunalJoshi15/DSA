#include<bits/stdc++.h>

using namespace std;
/*
In the adjacency list we will be defining the nodes.
All the individual elements of the array are present in the list.
*/
class Graph{
	// These are the lists of integers.  These are basically the array of lists. Here the dynamic allocation is used for defining the array of lists.
public:
	int V;
	list<int> *l;
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}

	void printGraph(){
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			//We will be printing all the element of the ith linkedlist.
			for(auto node:l[i]){
				cout<<node<<"-->";
			}
			cout<<endl;
		}
	}
};	

int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);

	g.printGraph();
} 