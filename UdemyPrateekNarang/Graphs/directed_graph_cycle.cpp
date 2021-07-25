#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
	int V;
	list<int> *l;
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
	}
	bool dfs(int node,vector<bool> &visited,vector<bool> &stack){
		visited[node] = true;
		stack[node] =true;
		for(int nbrs:l[node]){
			if(stack[nbrs]==true){
				return true;
			}
			else if(visited[nbrs]=false){
				bool nbrFoundCycle = dfs(nbrs,visited,stack);
				if(nbrFoundCycle) return true;
			}
		}
		stack[node]=false;
		return false;
	}
	bool contains_cycle()
	{
		vector<bool> visited(V,false);
		vector<bool> stack(V,false);
		// Inside the call stack we will be having the information regarding whether the node is in call stack or not.
		for(int i=0;i<V;i++){
			if(!visited[i]){
				if(dfs(i,visited,stack)){
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);

	return 0;
}
