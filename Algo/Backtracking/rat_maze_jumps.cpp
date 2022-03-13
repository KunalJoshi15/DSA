#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> maze[],int N,int i,int j){
	if(i<N and j<N and maze[i][j]>0){
		return true;
	}
	return false;
}

bool goTo(vector<int> maze[],int N,int i,int j,vector<int> result[]){
	if(i==n-1 and j==n-1){
		result[i][j] = 1;
		return true;
	}

	if(isSafe(maze,N,i,j)){
		int jumps = maze[i][j];
		result[i][j] = 1;
		for(int k=1;k<=jumps;k++){
			if(goTo(maze,N,i+k,j,result)){
				return true;
			}
			if(goTo(maze,N,i,j+k,result)){
				return true;
			}
		}
		result[i][j] = 0;
		return false;
	}
	return false;
}

void solve(int N,vector<int> adj[]){
	vector<int> res[N];
	for(int i=0;i<N;i++){
        result[i].assign(N,0);
    }
    if(goTo(maze,N,0,0,result)==true){
        print(N,result);
        return;
    }
    cout<<"-1\n";
    return;
}

int main()
{
	int N;
	cin>>N;
	vector<int> adj[N];
}