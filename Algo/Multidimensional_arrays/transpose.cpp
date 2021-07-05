#include<bits/stdc++.h>

using namespace std;

void transpose(int mat[4][4]){
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}

int main()
{
    int m=4,n=4;
    int temp[n][n];
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j] = arr[j][i];
        }
    }
    // Diagonal elements always remain the same in both the matrices.
    // Therefore we can do this even without using a temporary array.
    // There is one more efficient solution in which we will be simply swapping the values that we currently have.
    //Now simply copy the temporary array to the orignal array.
}