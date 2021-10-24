#include<bits/stdc++.h>
using namespace std;

#define Ver 4

class Graph{
public:
	int V;
	vector<pair<int,int>> *l;

	Graph(int V){
		this->V = V;
		l = new vector<pair<int,int>>[V];
	}

	void addEdge(int src,int dest,int w){
		l[src].push_back({dest,w});
		l[dest].push_back({src,w});
	}

	vector<int> dijkstra(int src){
		vector<int> dist(V,INT_MAX);
		dist[src]=0;

		vector<bool> fin(V,false);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({0,src});

		while(pq.empty()==false){
			auto x = pq.top();
			pq.pop();
			int to = x.second;
			int weight = x.first;

			for(pair<int,int> nbrs:l[to]){
				int x = nbrs.first;
				int w = nbrs.second;

				if(dist[x]>dist[to]+w){
					dist[x] = dist[to]+w;
					pq.push({dist[x],x});
				}
			}
		}
		return dist;
	}

	
};
vector<int> dijkstraMatrix(int graph[Ver][Ver],int src){
		vector<int> dist(Ver,INT_MAX);

		dist[src] = 0;
		vector<bool> fin(Ver,false);

		for(int count=0;count<Ver;count++){
			int u = -1;

			for(int i=0;i<Ver;i++){
				if(!fin[i] and (u==-1||dist[i]<dist[u])){
					u = i;
				}
			}
			// we have found the node which is in the smallest distance.
			fin[u]=true;
			// here we have starting exploring that particular node which we have currently found.
		
			for(int v=0;v<Ver;v++){
				if(graph[u][v]!=0 and fin[v]==false){
					dist[v]= min(dist[v],dist[u]+graph[u][v]);
				}
			}
		}
		return dist;
	}

int main()
{
	Graph g(4);
	g.addEdge(0,1,50);
	g.addEdge(0,2,100);
	g.addEdge(1,2,30);
	g.addEdge(1,3,200);
	g.addEdge(2,3,20);

	for(int x:g.dijkstra(0)){
		cout<<x<<" ";
	}
	cout<<endl;
	int graph[Ver][Ver] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: dijkstraMatrix(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
}