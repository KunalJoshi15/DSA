#include<bits/stdc++.h>

using namespace std;
// c abd d is the edge which is provided to use we have to check whether this edge is bridge or not.
int in[20001];
int low[20001];
int timer=0;
int f=0;
bool vis[200001];

void dfs(vector<int> adj[],int node,int parent,int c,int d){
	vis[node] =true;
	low[node] = in[node] = ++timer;
	for(int child:adj[node]){
		if(child==par){
			continue;
		}

		if(vis[child]){
			// low time of the node will be the value which is smaller between the discovery time of the child and the current low time of the node.
			low[node] = min(low[node],in[child]);
		} else {
			dfs(adj,child,node,c,d);
			low[node] = min(low[node],low[child]);
			if(low[child]>in[node]){
				if(child==c and node==d||child==d and node=c){
					f = 1;
				}
			}
		}
	}
}

int isBridge(int V,vector<int> adj[],int c,int d){
	f = 0;
	timer = 0;

	for(int i=0;i<V;i++){
		vis[i] = false;
		in[i] = 0;
	}

	for(int i=0;i<V;i++){
		if(vis[i]==false){
			dfs(adj,i,-1,c,d);
		}
	}
	return f;
}