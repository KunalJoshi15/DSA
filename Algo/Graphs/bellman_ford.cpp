#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
	int V;
	list<pair<int,int>> *l;

	Graph(int V){
		this->V = V;
		l = new list<pair<int,int>>[V];
	}
	// here the graph is directed
	void addEdge(int src,int dest,int w){
		l[src].push_back({dest,w});
	}

	void BellmanFord(int src){
		int v = V;
		int e = 5;
		int dist[v];
		for(int i=0;i<v;i++){
			dist[v] = INT_MAX;
		}

		dist[src] = 0;
		// here the loop will run v-1 times as we will be able to find the shortest path in these many iterations time complexity of this function is O(VE);
		for(int i=1;i<=v-1;i++){
			// for all the edges we will be looping.
			for(int j=0;j<v;j++){
				for(pair<int,int> nbrs:l[j]){
					int first = j;
					int second = nbrs.first;
					int weight = nbrs.second;
					// printf("src:%d dest:%d weight:%d\n",first,second,weight);
					if(dist[first]!=INT_MAX and dist[first]+weight<dist[second]){
						dist[second] = dist[first]+weight;
						// cout<<"HERE I AM"<<endl;
					}
				}
			}
		}

		for(int i=0;i<v;i++){
			for(pair<int,int> nbrs:l[i]){
				int first = i;
				int second = nbrs.first;
				int weight = nbrs.second;

				if(dist[first]!=INT_MAX and dist[first]+weight<dist[second]){
					cout<<"Graph contains negative weight cycle";
					return;
				}
			}
		}
		for(int i=0;i<v;i++){
			printf("vertex:%d dist:%d\n",i,dist[i]);
		}
		return;
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(0,2,4);
	g.addEdge(1,2,-3);
	g.addEdge(1,3,2);
	g.addEdge(2,3,3);
	// here we have provided the starting vertex of the graph.
	g.BellmanFord(0);
}