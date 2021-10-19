#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
	int V;
	list<int> *adj;

	Graph(int V){
		this->V=V;
		adj = new list<int>[V];
	}

	void addEdge(int source,int dest,bool undir=false){
		adj[source].push_back(dest);
		if(undir){
			adj[dest].push_back(source);
		}
	}

	void bfs(int source){
		queue<int> q;
		q.push(source);
		bool visited[V]={false};
		visited[source]=true;
		while(q.empty()==false){
			int curr = q.front();
			cout<<curr<<" ";
			q.pop();
			for(int nbrs:adj[curr]){
				if(visited[nbrs]==false){
					q.push(nbrs);
					visited[nbrs]=true;
				}
			}
		}
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,4);
	g.addEdge(2,3,true);

	g.bfs(0);
}