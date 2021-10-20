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
		l[dest].push_back(src);
	}

	bool dfs(int node,vector<bool> &visited,int parent){
		visited[node]=true;
		for(int i:l[node]){
			if(!visited[node]){
				// Here we will not be simply returning the value.
				// Here we need to check whether the neighbour is responsible for the formation of cycle or not.
				if(dfs(i,visited,node)){
					// If the cycle is found in case of the neighbour then simply return 1.
					return 1;
				}
			}else{
				if(i!=parent){
					return 1;
				}
			}
		}
		return 0;
	}

	bool contains_cycle(){
		vector<bool> visited(V,false);
		return dfs(0,visited,-1);
	}
	// there is one more for loop which is to be used as in case if the graph is disconencted then we need to consider even more nodes as per our requirement.
	// 1 -- 2 -- 3
// this particular approach leverages the idea of the bfs in order to detect whether the cycle exists or not.
	bool cycleExists(){
		vector<bool> visited(V,false);
		queue<int> q;
		q.push(0);
		visited[V]=true;
		vector<int> parent(V,-1);

		while(q.empty()==false){
			int curr = q.front();
			q.pop();

			for(int nbrs:l[curr]){
				if(!visited[nbrs]){
					visited[nbrs]=true;
					q.push(nbrs);
					parent[nbrs] = curr;
				}
				else{
					if(parent[nbrs]!=curr){
						return true;
					}
				}
			}
		}
		return false;
	}
};


int main()
{
	Graph g(7);
		g.addEdge(0,1);
		g.addEdge(1,2);
		g.addEdge(2,3);
		g.addEdge(3,5);
		g.addEdge(5,6);
		// g.addEdge(4,5);
		// g.addEdge(0,4);
		// g.addEdge(3,4);
		if(g.contains_cycle()){
			cout<<"CYCLE";
		}
		else{
			cout<<"NO CYCLE";
		}

		if(g.cycleExists()){
			cout<<"CYCLE";
		}
		else{
			cout<<"NO CYCLE";
		}
}
/*
0   1    2    3    5  6
*/
