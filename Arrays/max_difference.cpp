#include<bits/stdc++.h>

using namespace std;
// Here we need to find the maximum result of arr[j]-arr[i] such that j>i
int maxDiff(int *arr,int n){
    int res = arr[1]-arr[0];

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++){
            res = max(res,arr[j]-arr[i]);
        }
    }
    //for each and every pair where j>i this is calculated.
    return res;
}

int maxDiff1(int *arr,int n){
    int res = arr[1]-arr[0];
    int minVal = arr[0];
    // We will be keeping the track of the min element of the array as the min element will most probably be included.
    for(int i=1;i<n;i++){
        res = max(res,arr[i]-minVal);
        minVal=min(minVal,arr[i]);
    }
    return res;
}
// The above solution is O(n) and only constant auxiliary space is required.

int main()
{
    int arr[] = {5,7,3,2,3,4,6,7};
    int n = sizeof(arr)/sizeof(int);


}