#include<bits/stdc++.h>
using namespace std;

int search_rotated(int *arr,int n){
    // In order to reach to an O(log n) solution we will have to identify which part of the array is sorted. This can be determined by checking the value in the mid.
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x) return mid;
        if(arr[low]<arr[mid]){
            // This means that the left part of the array is sorted.
            if(x>arr[low] and x<arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }else{
            // This means that the right half of the array is sorted;
            if(x>arr[mid] and x<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,5,9};
    int index = search_rotated(arr,sizeof(arr)/sizeof(int));
}