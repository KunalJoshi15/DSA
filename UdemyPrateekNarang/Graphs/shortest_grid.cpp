#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int x;
    int y;
    int dist;

    Node(int x,int y,int dist)
    {
        this->x=x;
        this->y=y;
        this->dist = dist;
    }
};

class Compare{
    // TELLS WHICH WILL COME FIRST AND SECOND.
public:
    bool operator()(const Node &a,const Node &b){
        return a.dist<=b.dist;
    }
};

// Here even the set of vectors can be used and then define a comparator to work with it.
int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int m = grid.size();
    int n = grid[0].size();

    int i=0,j=0;

    vector<vector<int>> dist(m+1,vector<int>(n+1,INT_MAX));

    // We can move to these 4 directions In case of the 8 way dfs the approach is different.
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    dist[i][j] = grid[0][0];
    // HEre we will be creating a set of 
    set<Node,Compare> s;
    s.insert(Node(0,0,dist[0][0]));

    while(!s.empty()){
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;

        s.erase(it);

        for(int k=0;k<4;k++){
            int nx = cx+dx[k];
            int ny = cy+dy[k];

            if(nx>=0 and nx<m and ny>=0 and ny<n and cd+grid[nx][ny]<dist[nx][ny]){
                // This is within the range.
                // Remove the old node if it exists.
                auto f = s.find(Node(nx,n,dist[nx][ny]));
                if(f!=s.end()){
                    s.erase(f);
                }

                int nd = grid[nx][ny]+cd;
                dist[nx][ny]=nd;
                s.insert(Node(nx,ny,nd));
            }
        }   
    }
    return dist[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid = {
        {31,100,65,12,18},
        {10,13,47,157,6},
        {100,113,174,11,33},
        {88,124,41,20,140},
        {99,32,111,41,20}
    };
    cout<<shortest_path(grid);
}
