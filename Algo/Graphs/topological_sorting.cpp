#include<bits/stdc++.h>

using namespace std;
// in case of the topological sorting we will be doing one task before and the other task after that as per our requirment.
class Graph{
public:
	int V;
	list<int> *l;

	Graph(int V){
		this->V=V;
		l = new list<int>[V];
	}

	void addEdge(int src,int dest,bool undir=false){
		l[src].push_back(dest);

		if(undir){
			l[dest].push_back(src);
		}
	}
	// here we need to store the indegree of all the vertices which are present as per our requirement.
	// this particular method is using the kahn based approach.
	void topologicalSort(){
		// find the indegree for all the vertices which are present in the graph the one with the 0 indegree will be the one which are printed first.
		// after this the other nodes will be printed as per our requirement.

		vector<int> in_degree(V,0);
		// here the time complexity of finding this is O(V+E)
		for(int u = 0;u<V;u++){
			for(int x: l[u]){
				in_degree[x]++;
			}
		}
		// insert all the vertices which have the indegree as 0 inside the queue and then we will be performing the simple bfs.
		queue<int> q;
		for(int i=0;i<V;i++){
			if(in_degree[i]==0)
				q.push(i);
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();
			cout<<u<<" ";

			for(int x:l[u]){
				in_degree[x]--;
				if(in_degree[x]==0){
					q.push(x);
				}
			}
		}
	}

	void DFS(int src,stack<int> &stk,bool visited[]){
		visited[src] = true;

		for(int x:l[src]){
			if(visited[x]==false){
				DFS(x,stk,visited);
			}
		}
		stk.push(src);
	}

	void topologicalSortUtil(){
		stack<int> stk;
		bool visited[V] = {false};
		for(int i=0;i<V;i++){
			if(!visited[i]){
				DFS(i,stk,visited);
			}
		}

		while(stk.empty()==false){
			int u = stk.top();
			stk.pop();
			cout<<u<<" ";
		}
	}
};
// we can find the order in which the orders needs to be run.
// we can find the incoming edges and that can be used.
// ways to finish the project  without any deadlock.
// this is basically a bfs based solution we will be finding the nodes which have 0 degree.
int main()
{
	Graph g(5);
	g.addEdge(0, 1); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(2, 4);  
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort();
    cout<<endl;
    g.topologicalSortUtil();
	return 0; 
}