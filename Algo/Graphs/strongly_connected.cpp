#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int> *adj;

	void fillOrder(int v,bool visited[],stack<int> &s);

	void DFSUtil(int v,bool visited[]);

public:
	Graph(int V);

	void addEdge(int v,int w);

	Graph getTranspose();
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::fillOrder(int v,bool visited[],stack<int> &s){
	visited[v] = true;

	list<int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end();++i){
		if(!visited[*i]){
			fillOrder(*i,visited,s);
		}
	}
	s.push(v);
}

void Graph::printSCC(){
	stack<int> s;

	bool visited[] = new int[V];
	for(int i=0;i<V;i++){
		if(visited[i]==false){
			fillorder(i,visited,s);
		}
	}

	Graph gr = getTranspose();
}

int main()
{
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 

	cout << "Following are strongly connected components in given graph \n"; 
	g.printSCCs(); 

	return 0; 
}