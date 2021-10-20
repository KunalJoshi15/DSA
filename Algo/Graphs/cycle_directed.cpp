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

		if(undir){
			l[dest].push_back(src);
		}
	}
};

int main()
{

}