#include<bits/stdc++.h>

using namespace std;

int first_occurence(int *arr,int n,int x){
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==x){
            if(mid==0 || arr[mid-1]!=arr[mid]){
                return mid;
            }
            else{
                high=mid-1;
            }
        }
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int last_occurence(int *arr,int n,int x){
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==x){
            if(mid==n-1||arr[mid+1]!=arr[mid]) return mid;
            else {
                low=mid+1;
            }
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[]  = {1,2,3,3,3,3,3,5,6,7,8};
    int n = sizeof(arr)/sizeof(int);
    int x=3;
    int first = first_occurence(arr,n,x);
    int last = last_occurence(arr,n,x);
    // Total occurences can be found using the start index and the ending index of the values that we currently have.
}