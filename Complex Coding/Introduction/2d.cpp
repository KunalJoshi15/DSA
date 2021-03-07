#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }
    int i=0;
    int j=0;
    while(j<n){
        if(j%2==0){
            for(int k=0;k<n;k++){
                cout<<arr[k][j]<<" ";
            }
        }
        else{
            for(int k=n-1;k>=0;k--){
                cout<<arr[k][j]<<" ";
            } 
        }
        j++;
    }
}