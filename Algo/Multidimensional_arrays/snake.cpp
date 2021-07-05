#include<bits/stdc++.h>

using namespace std;

void snake_pattern(int arr[4][4],int m,int n){
    int i=0,j=0;

    while(i<n){
        if(i%2==0){
            for(int k=0;k<n;k++){
                cout<<arr[i][k]<<" ";
            }
            i++;
        }
        else{
            for(int k=n-1;k>=0;k--){
                cout<<arr[i][k]<<" ";
            }
            i++;
        }
    }
}
int main()
{
    // This particular solution is used to print the snake pattern in the arrays.
    int m=4,n=4;
    int arr[m][n] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    snake_pattern(arr,m,n);
}