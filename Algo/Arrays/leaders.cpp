#include<bits/stdc++.h>

using namespace std;
// A leader is an element that has all the elements smaller to the right of it.
int leader(int arr[],int n){
    for(int i=0;i<n;i++){
        bool m=false;
        for(int j=i+1;j<n;j++){
            if(arr[i]<=arr[j]){
                m=true;
                break;
            }
        }
        if(m==false) cout<<arr[i];
    }
    // This particular solution is an O(n^2) for printing all the leaders that are present in an array.
}

int leader1(int arr[],int n){
    int curr_lead = arr[n-1];
    cout<<curr_lead;
    for(int i=n-2;i>=0;i--){
        if(curr_lead<arr[i]){
            curr_lead=arr[i];
            cout<<curr_lead;
        }
    }
}
// This particular solution is an O(n) solution in it we have the current leader.
int main()
{
    // return -1 if there are no leaders.
    int arr[] = {6,5,2,4,2,1};
    // In case the array is in ascending order the elements that are on the right side are alwaus larger.
    // Naive approach provides us the O(n^2) solution
}