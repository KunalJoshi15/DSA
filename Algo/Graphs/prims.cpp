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

	void addEdge(int src,int dest,int w){
		l[src].push_back({w,dest});
	}

	int primsMST(){
		int ans=0;
		vector<bool> visited(V,false);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({0,0});
		while(pq.empty()==false){
			pair<int,int> x = pq.top();
			pq.pop();


			if(visited[x.second]){
				continue;
			}
			ans+=x.first;
			visited[x.first] = true;
			for(pair<int,int> nbrs:l[x.second]){
				if(!visited[nbrs.first]){
					pq.push({nbrs.first,nbrs.second});
				}
			}
		}
		return ans;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;

	Graph g(n);
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		g.addEdge(x-1,y-1,w);
	}

	cout<<g.primsMST()<<endl;
}