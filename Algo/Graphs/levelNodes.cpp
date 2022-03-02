#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int> adj[],vector<bool> visited,int X,int &ans,int i){
	visited[i] = true;
	queue<int> q;
	q.push(i);
	int level = 0;
	while(q.empty()==false){
		int cnt = q.size();

		for(int i=0;i<cnt;i++){
			int curr = q.front();
			if(curr==x){
				ans = level;
			}
			q.pop();

			for(auto &e:adj[curr]){
				if(visited[e]==false){
					q.push(e);
					visited[e]=true;
				}
			}
		}
		level++;
	}
}

int nodeLevel(int V,vector<int> adj[],int X){
	vector<bool> visited(V,false);
	int ans=-1;

	for(int i=0;i<V;i++){
		if(visited[i]==false){
			bfs(adj,visited,X,ans,i);
		}
	}
	return ans;
}

int main(){

}