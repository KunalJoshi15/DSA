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

	void addEdge(int src,int dest,bool undir=false){
		l[src].push_back(dest);

		if(undir){
			l[dest].push_back(src);
		}
	}

	// we can use dfs in this case as well.
	bool dfs(int node,vector<bool> &visited,vector<bool> stack){
			visited[node] = true;
			stack[node] = true;

			for(int nbrs:l[node]){
				// if the nbr was reached before as well in current case then we will return that there is cycle present.
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

// in the directed graph as well we can perform the searching as per our requiirement.


int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);
    g.addEdge(2, 3);
    // g.addEdge(3, 3);
 
    if(g.detectCycle(0))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}