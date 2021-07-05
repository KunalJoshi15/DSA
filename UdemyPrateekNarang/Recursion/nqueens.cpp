#include<bits/stdc++.h>

using namespace std;

bool isSafe(int **sol,int row,int col,int n){
    for(int i=0;i<col;i++)
    {
        if(sol[row][i]){
            return false;
        }
    }
    int x=row;
    int y=col;
    while(x>=0 && y>=0){
        if(sol[x][y]){
            return false;
        }
        x--;
        y--;
    }

    x=row;
    y=col;
    while(x>=0 && y<n){
        if(sol[x][y]){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nQueens(int **sol,int row,int n){
    if(row==n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(sol,row,col,n)){
            sol[row][col]=1;
            if(nQueens(sol,row+1,n)){
                return true;
            }
            sol[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int **arr = new int*[n];

    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    bool solution = nQueens(arr,0,n);
    if(solution){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}