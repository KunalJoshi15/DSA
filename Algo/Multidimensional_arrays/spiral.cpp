#include<bits/stdc++.h>

using namespace std;
// Here in order to print a particular matrix in the spiral form we will require 4 varaibles.
// top,right,left and bottom all represents the extreme ends of the 2-D Matrix.

void spiral(int arr[][4],int m,int n){
    int top=0;
    int left=m-1;
    int right=n-1;
    int bottom=n-1;

    // After each values will be changed one after the other.
    while(top<=bottom and left<=right){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;

        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i++){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
}

int main()
{
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
}