#include<bits/stdc++.h>

using namespace std;
// we can use belmann ford and dijkstra.
// traverse through all the vertices in topological order.
// here the first part represent the destination node and the second part has the weight.
class Graph{
public:
	int V;
	list<pair<int,int>> *l;

	Graph(int V){
		this->V = V;
		l = new list<pair<int,int>>[V];
	}

	void addEdge(int src,int dest,int w){
		l[src].push_back({dest,w});
	}
	// since the graph is dag therefore we can simply use this particular approach.
	void topologicalSort(int v,bool visited[],stack<int> &stack){
		// visited the particular node with which we are starting.
		visited[v] = true;

		for(pair<int,int> x:l[v]){
			int node = x.first;
			if(!visited[node])
				topologicalSort(node,visited,stack);
		}
		// all the nodes are pushed using their topological ordering into the stack.
		stack.push(v);
	}

	void shortestPath(int s){
		stack<int> stack;
		int dist[V];

		bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i]=false;
		}

		for(int i=0;i<V;i++){
			if(visited[i]==false){
				topologicalSort(i,visited,stack);
			}
		}

		for(int i=0;i<V;i++){
			dist[i] = INT_MAX;
		}
		dist[s] = 0;

		while(stack.empty()==false){
			int u = stack.top();
			stack.pop();

			if(dist[u]!=INT_MAX){
				for(pair<int,int> x:l[u]){
					if(dist[x.first]>dist[u]+x.second){
						dist[x.first] = dist[u]+x.second;
					}
				}
			}
		}

		for(int i=0;i<V;i++){
			if(dist[i]==INT_MAX)
			{
				cout<<"INF ";
			}
			else{
				cout<<dist[i]<<" ";
			}
		}
	}
};

int main()
{
	Graph g(6); 
	g.addEdge(0, 1, 2); 
	g.addEdge(0, 4, 1); 
	g.addEdge(1, 2, 3); 
	g.addEdge(4, 2, 2); 
	g.addEdge(4, 5, 4); 
	g.addEdge(2, 3, 6); 
	g.addEdge(5, 3, 1);
/*
	0->1->4
	1->2
	2->3
	4->2->5
	5->3

	0 
*/
	int s = 0; 
	cout << "Following are shortest distances from source " << s <<" \n"; 
	g.shortestPath(s); 

	return 0;
}