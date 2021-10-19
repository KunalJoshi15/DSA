#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
	int V;
	list<int> *l;

	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int source,int dest,bool undir=false){
		l[source].push_back(dest);

		if(undir){
			l[dest].push_back(source);
		}
	}
	// this is the dfs utility function which is used for the recursion aspect of the coding.
	void dfs_util(int source,vector<bool> &visited){
		visited[source] = true;
		cout<<source<<" ";
		for(int nbrs:l[source]){
			if(!visited[nbrs]){
				dfs_util(nbrs,visited);
			}
		}
	}

	void dfs(int source){
		vector<bool> visited(V,false);
		int count=0;
		for(int i=0;i<V;i++){
			if(!visited[i]){
				dfs_util(i,visited);
				count++;
			}
		}
		cout<<"Total number of connected components are"<<count<<endl;
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);

	g.dfs(1);
}