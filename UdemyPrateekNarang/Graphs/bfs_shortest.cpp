#include<bits/stdc++.h>

using namespace std;
/*
Here during the implementation we can define the array as the parent one and the distance from the source.
*/
class Graph{
	int V;
	list<int> *l;
public:
	Graph(int V){
		this->V=V;
		l = new list<int>[V];
	}

	void addEdge(int a,int b,bool undir=false){
		l[a].push_back(b);
		if(undir) l[b].push_back(a);
	}

	void findDist(int src,int destination=-1){
		queue<int> q;
		bool *visited = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V];
		for(int i=0;i<V;i++){
			parent[i]=-1;
		}

		q.push(src);
		visited[src]=true;
		parent[src]=src;
		dist[src]=0;
		while(!q.empty()){
			int curr = q.front();
			// cout<<curr<<endl;
			q.pop();

			for(auto nbr:l[curr]){
				if(!visited[nbr]){
					q.push(nbr);
					dist[nbr] = dist[curr]+1;
					parent[nbr] = curr;
					visited[nbr]=true;
				}
			}
		}
		// This particular algorithm is also called the single source shortest path algorithm.
		// Print the shortest distance 
		for(int i=0;i<V;i++){
			cout<<"Shortest dist to "<<i<<"is "<<dist[i]<<endl;
		}
		if(destination!=-1){
			int temp = destination;
			while(temp!=src){
				cout<<temp<<"-->";
				temp = parent[temp];
			}
			cout<<src;
		}
	}
};


int main()
{
	Graph g(5);
	g.addEdge(0,1,true);
	g.addEdge(2,3,true);
	g.addEdge(3,1,true);
	g.addEdge(4,2,true);
	g.addEdge(0,3);
	g.findDist(0,4);
}