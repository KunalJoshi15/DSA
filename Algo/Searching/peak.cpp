#include<bits/stdc++.h>

using namespace std;

int getPeak(int arr[],int n){
    if(n==1) return arr[0];
    if(arr[0]>=arr[1]) return arr[0];
    if(arr[n-1]>=arr[n-2]) return arr[n-1];
    // THis is the linear time solution of the problem.
    for(int i=1;i<n-1;i++){
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]) return arr[i];
    }
}

int getPeak2(int arr[],int n){
    int low = 0,high=n-1;

    while(low<=high){
        int mid = (low+high)/2;
        // mid==0 means that the element which is present is the first element. If not the first element then the second condition in the or case is called.
        // very elegant way of writing the solution to a particular question is this particular way.
        if((mid==0||arr[mid-1]<=arr[mid])&&(mid==n-1||arr[mid+1]<=arr[mid])) return mid;
        // If the peak element is not on the left side then we will move to the right side for finding the particular peak element.
        if(mid>0 && arr[mid-1]>=arr[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main()
{
    // A particular element is a peak element if that element is not smaller than its neighbour.
}