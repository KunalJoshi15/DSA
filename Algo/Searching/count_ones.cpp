#include<bits/stdc++.h>

using namespace std;

int first_occurence(int *arr,int n){
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==1){
            if(mid==0||arr[mid-1]!=arr[mid]) return mid;
            else high=mid-1;
        }
        else if(arr[mid]<1){
            low=mid+1;
            // Not many cases rather than this will be required
        }
    }
    return -1;
    // If the value which is returned as -1 then we can simply say that the element is not present in the array for which we are searching.
}

int main(){
    int arr[]  = {0,0,0,0,1,1,1,1,1,1};
    // We can simply perform the linear search and find the complete count in this particular case.
    // We can implement the binary search and find the first occurence of the array and then subtract it with n-1 which is the size of the array.
    int first = first_occurence(arr,sizeof(arr)/sizeof(int));
}