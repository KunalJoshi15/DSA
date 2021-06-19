#include<bits/stdc++.h>

using namespace std;

int remDup(int arr[],int n){
    int temp[n];
    temp[0]=arr[0];
    int res=1;

    for(int i=1;i<n;i++){
        if(temp[res-1]!=arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        arr[i]=temp[i];
    }
    return res;
}

int main(){
    // Inside the main this particular function will be called as per our own need.
    return 0;
}