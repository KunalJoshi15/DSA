#include<bits/stdc++.h>
#define NIL -1
using namespace std;

class Graph{
public:
	int V;
	list<int> *adj;

	void SCCUtil(int u,int disc[],int low[],stack<int> *st,bool stackMember[]);
	
	Graph(int V);
	void addEdge(int v,int w);
	void SCC();
};

Graph::Graph(int V){
	this->V=V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

// this particular function will be used for finding the strongly connected components.
void Graph::SCCUtil(int u,int disc[],int low[],stack<int> *st,bool stackMember[]){
	static int time = 0;
	st->push(u);
	stackMember[u] = true;
	disc[u] = low[u] = ++time;
	list<int>::iterator i;

	for(i=adj[u].begin();i!=adj[u].end();i++){
		int v = *i;

		if(disc[v]==-1){
			SCCUtil(v,disc,low,st,stackMember);
			low[u] = min(low[u],low[v]);
		}
		else if(stackMember[v]==true){
			low[u] = min(low[u],disc[v]);
		}
	}
	int w = 0;
	if(low[u]==disc[u]){
		while(st->top()!=u){
			w = (int)st->top();
			cout<<w<<" ";
			stackMember[w] = false;
			st->pop();
		}
		// this will pop the current node only which means that it is a single node component if above condition is false.
		w = (int)st->top();
		cout<<w<<"\n";
		stackMember[w] = false;
		st->pop();
	}
}

void Graph::SCC()
{
	int *disc = new int[V];
	int *low = new int[V];
	bool *stackMember = new bool[V];
	stack<int> *st = new stack<int>();

	for(int i=0;i<V;i++){
		disc[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

	for(int i=0;i<V;i++){
		if(disc[i]==NIL){
			SCCUtil(i,disc,low,st,stackMember);
		}
	}
}

int main() 
{ 
	cout << "SCCs in the graph \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.SCC(); 

	return 0; 
} 