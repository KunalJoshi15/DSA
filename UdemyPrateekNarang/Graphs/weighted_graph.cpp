#include<bits/stdc++.h>

using namespace std;

class Graph{
	// This represents the name of the vertex.
	int V;
	// We will be dynamically allocate the graph that we are creating.
	list<pair<int,int>> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<pair<int,int>>[V];
	}
	// Here a is the source vertex and b be the destination vertex and w is the weight of the edge.
	void addEdge(int a,int b,int w,bool undir=false){
		l[a].push_back({b,w});
		if(undir){
			l[b].push_back({a,w});
		}
	}

	void printGraph(){
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			for(auto m:l[i]){
				cout<<"{"<<m.first<<","<<m.second<<"}->";
			}
			cout<<endl;
		}
	}
};

int main()
{
	Graph g(6);
	g.addEdge(0,2,3,true);
	g.addEdge(0,5,23);
	g.addEdge(1,0,5);
	g.addEdge(3,4,12,true);
	g.addEdge(5,3,21,true);
	g.printGraph();
}