#include<bits/stdc++.h>

using namespace std;
// shortest path in case of the undirected graph can be found using only bfs. Therefore time complexity in this particular case is O(V+E)
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
		if(undir==true){
			l[dest].push_back(src);
		}
	}

	void findShortest(int src,int dest){
		queue<int> q;
		q.push(src);
		vector<int> dist(V,INT_MAX);
		vector<bool> visited(V,false);
		dist[src] = 0;
		visited[src]=true;
		while(q.empty()==false){
			int curr = q.front();
			q.pop();

			for(int nbrs:l[curr]){
				if(!visited[nbrs]){
					visited[nbrs]=true;
					dist[nbrs]=dist[curr]+1;
					q.push(nbrs);
				}
			}

		}
		for(int x:dist){
			cout<<x<<" ";
		}
		// cout<<dist[dest]<<endl;
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0,1,true);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);

	g.findShortest(1,2);
}