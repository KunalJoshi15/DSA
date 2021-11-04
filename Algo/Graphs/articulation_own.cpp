#include<bits/stdc++.h>

using namespace std;

#define NIL -1;

class Graph{
public:
	int V;
	list<int> *adj;

	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}

	void addEdge(int src,int dest,bool undir=false){
		adj[src].push_back(dest);

		if(undir){
			adj[dest].push_back(src);
		}
	}

	void APUtil(int u,bool *visited,int *disc,int *low,int *parent,bool *ap){
		// this particular time can be passed using as parameter.
		static int time = 0;
		int children;

		visited[u] = true;
		disc[u] = low[u] = ++time;
		// using this particular iterator we can iterate through all the values.
		list<int>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i){
		int v = *i;

		if(!visited[v]){
			children++;
			parent[v] = u;
			APUtil(v,visited,disc,low,parent,ap);
			
			low[u] = min(low[u],low[v]);
			if(parent[u]==-1 and children>1)
				ap[u]=true;
			if(parent[u]!=-1 and low[v] >= disc[u])
				ap[u] = true;
			}
			else if(v!=parent[u]){
				low[u] = min(low[u],disc[v]);
			}
		}
	}

	void AP(){
		bool *visited = new bool[V];
		int *disc = new int[V];
		int *low = new int[V];
		int *parent = new int[V];
		bool *ap = new bool[V];

		for (int i = 0; i < V; i++) 
		{	 
			// initialize all the arrays as per our requirement.
			parent[i] = NIL; 
			visited[i] = false; 
			ap[i] = false; 
		}

		for(int i=0;i<V;i++){
			if(!visited[i]){
				APUtil(i,visited,disc,low,parent,ap);
			}
		}

		for(int i=0;i<V;i++){
			if(ap[i]){
				cout<<i<<" ";
			}
		}
	}
};
/*
A particular nod can be an articulation point only if it follows the certain policies. If the node is not a root node and has at least one children with low[u] >= discovery time of the node
*/
int main()
{
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.AP();

	return 0;
}