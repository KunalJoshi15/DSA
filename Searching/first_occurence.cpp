#include<bits/stdc++.h>

using namespace std;

int first_occur(int *arr,int low,int high,int key){
    
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(key>arr[mid]){
        return first_occur(arr,mid+1,high,key);
    }
    else if(key<arr[mid]){
        return first_occur(arr,low,mid-1,key);
    }
    else{
        if(mid==0 || arr[mid-1]!=arr[mid]){
            return mid;
        }
        return first_occur(arr,low,mid-1,key);
    }
}

int main(){
    int arr[] = {1,1,2,3,3,3,4,5,6,7,7,7,8};
    int key=7;
    int first_occurence = first_occur(arr,0,sizeof(arr)/sizeof(int)-1,key);
    return 0;
}