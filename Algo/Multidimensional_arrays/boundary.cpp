#include<bits/stdc++.h>

using namespace std;

void boundary_traversal(int arr[][4],int m,int n){
    if(m==1){
        // For the condition where there is only one row.
        for(int i=0;i<n;i++){
            cout<<arr[0][i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            cout<<arr[0][i]<<" ";
        }

        for(int i=1;i<m;i++){
            cout<<arr[i][n-1]<<" ";
        }

        for(int i=n-2;i>=0;i--){
            cout<<arr[m-1][i]<<" ";
        }
        for(int i=m-2;i>=1;i--){
            cout<<arr[i][0]<<" ";
        }
    }

}

// While printing the elements in the array there are some corner cases that needs to be considered.
int main()
{
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    boundary_traversal(arr,4,4);
    // In corner case we will be simply printing that row seperately otherise in the other cases the other things needs to be followed.
}