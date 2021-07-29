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

		void addEdge(int a,int b){
			l[a].push_back(b);
		}
		bool dfs(int node,vector<bool> &visited,vector<bool> stack){
			visited[node] = true;
			stack[node] = true;

			for(int nbrs:l[node]){
				if(stack[nbrs]){
					return true;
				}
				else if(visited[nbrs]==false){
					if(dfs(nbrs,visited,stack)){
						return true;
					}
				}
			}
			stack[node] = false;
			return false;
		}
		// Here we will be simply using the variation of the algorithm.
		bool detectCycle(int src){
			vector<bool> visited(V,false);
			vector<bool> stack(V,false);
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

/*
 *Here the technique that we will be simply using is that the We will be having two vectors one is for whether the node is visited or not while the other one represents whether the node is in the stack or not. 
 * */


int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(0,5);
	g.addEdge(2,3);

	if(g.detectCycle(0)){
		cout<<"There is cycle present in the class";
	}
	else{
		cout<<"There is no cycle in the class.";
	}
}
