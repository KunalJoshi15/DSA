#include<iostream>
#include<list>
#include<queue>
using namespace std;
// In case of the snakes and ladder question we will be creating a graph from each of the edge.
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int a,int b){
        l[a].push_back(b);
    }

    int minCostBST(int src,int dest){
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        queue<int> q;
        dist[src]=0;
        visited[src]=true;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto nbr:l[curr]){
                if(!visited[nbr]){
                    q.push(nbr);
                    dist[nbr] = dist[curr]+1;
                    visited[nbr]=true;
                }
            }
        }
        return dist[dest];
    }
};



int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    //Here w e have created a board.
    vector<int> board(n+1,0);

    for(auto sp:snakes){
    	// These two values represents the values from where to where the snake will take.
    	// The graph which will be created in this particular case is directed.
    	int s = sp.first;
    	int e = sp.second;

    	board[s] = e-s;
    }

    for(auto lp:ladders){
    	int s = lp.first;
    	int e = lp.second;

    	board[s] = e-s;
    }

    Graph g(n+1);
    // Here climbing the ladder is compulsory therefore we are therefore considering the values.
    for(int u=1;u<=n;u++){
    	for(int dice=1;dice<=6;dice++){
    		int v = u+dice;
    		v += board[v];

    		if(v<=n){
    			g.addEdge(u,v);
    		}
    	}
    }

    return g.minCostBST(1,n);
    
}

int main()
{
    vector<pair<int,int>> snakes = {
        {17,4},
        {20,6},
        {24,16},
        {34,12},
        {32,30}
    };
    vector<pair<int,int>> ladder = {
        {2,15},
        {5,7},
        {9,27},
        {28,29},
        {25,35}
    };
    cout<<min_dice_throws(36,snakes,ladder);
}