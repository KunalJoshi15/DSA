#include<bits/stdc++.h>

using namespace std;
/*
In case of the Breadth first search we traverse the nodes which are adjacent to the current node. 
BFS basically uses the idea of queue in order to traverse.
BFS algorithm can be used for finding the shortest path from one node to other nodes.
*/

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int V){
		this->V=V;
		// Here we have simply created a list of V elements.
		l = new list<int>[V];
	}

	void addEdge(int a,int b,bool undir=false){
		l[a].push_back(b);
		if(undir){
			l[b].push_back(a);
		}
	}

	void bfs(int src){
		vector<bool> visited(V,false);
		queue<int> q;
		q.push(src);
		visited[src]=true;
		while(!q.empty()){
			int top = q.front();
			cout<<top;
			q.pop();

			for(auto p:l[top]){
				if(!visited[p]){
					q.push(p);
					visited[p]=true;
				}
			}
		}
	}
};
// For implementing the idea of the BFS traversal we will be having a source from where the traversal will start.


int main()
{
	Graph g(5);
	g.addEdge(0,1,true);
	g.addEdge(2,3,true);
	g.addEdge(3,1,true);
	g.addEdge(4,2,true);
	g.addEdge(0,3);

	g.bfs(3);
}