#include<bits/stdc++.h>

using namespace std;

/*
In case of the single source shortest path algorithm we are provided with the single soruce and are asked to find 
the shortest path from this node to all other nodes which are present in the graph.

*/
class Graph{
public:
	int V;
	list<pair<int,int>> *l;

	Graph(int V){
		this->V = V;
		l = new list<pair<int,int>>[V];
	}

	void addEdge(int a,int b,int wt,bool undir=false){
		l[a].push_back({wt,b});
		if(undir){
			l[b].push_back({wt,a});
		}
	}

	int shortestPath(int src,int dest){
		vector<int> dist(V,INT_MAX);
		set<pair<int,int>> s;

		// 1. Init
		// Here we are using the set because we don't want more elements.
		dist[src]=0;
		s.insert({0,src});

		while(!s.empty()){
			auto it = s.begin();
			int distance = it->first;
			int node = it->second;
			// This will simply remove the element from the set.
			s.erase(it);

			for(pair<int,int> nbrs:l[node]){
				int edge = nbrs.first;
				int nbr = nbrs.second;

				if(distance+edge<dist[nbr]){
					auto f = s.find({dist[nbr],nbr});
					if(f!=s.end()){
						// This means that the pair is present.
						s.erase(f);
					}
					dist[nbr]=distance+edge;
					s.insert({dist[nbr],nbr});
				}
			}
		}
		return dist[dest];
	}
};

int main(){
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	int shortest = g.shortestPath(0,3);
	cout<<"SHORTEST PATH FROM 0 TO 3 is "<<shortest;
}