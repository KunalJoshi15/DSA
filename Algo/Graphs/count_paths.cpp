#include<bits/stdc++.h>

using namespace std;

void countPathHelper(int V,vector<int> adj[],int src,int dest,int &count){
	if(source==destination) count++;

	for(auto x:adj[source]){
		if(x==destination) count++;
		else{
			countPathHelper(V,adj,x,dest,count);
		}
	}
}

int countPaths(int V,vector<int> adj,int source,int destination){
	int count = 0;
	countPathHelper(V,adj,source,destination,count);
	return count;
}

int main()
{

}