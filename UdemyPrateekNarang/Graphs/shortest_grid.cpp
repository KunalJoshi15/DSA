#include<vector>
#include<set>
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
    bool operator()(const Node &a,const Node &b){
        return a.dist<=b.dist;
    }
};

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int m = grid.size();
    int n = grid[0].size();

    int i=0,j=0;

    vector<vector<int>> dist(m+1,INT_MAX);

    // We can move to these 4 directions
    int dx = {0,0,1,-1};
    int dy = {1,-1,0,0};
    
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