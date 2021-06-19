#include<bits/stdc++.h>

int search_infinite(int *arr,int x){
    // In case of the infinite sized array the first solution which comes to our mind is the O(pos) solution this will check all the elements till the position is found.
    // The better solution to this particular problem will be to implement the binary search and each time the index size is doubled. We will be getting a rough idea at which range our element might be present.
    int start=0;
    int end=1;
    while(arr[end]<x){
        end=end*2;
    }
    start = end/2;
    // The element will lie 
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
    // This algorithm will run with the time complexity of O(log pos)
}

int main(){
    int arr[] = {1,10,15,20,40,50};
    int x=50;
    int n = search_infinite(arr,x);
}