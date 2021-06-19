#include<bits/stdc++.h>

using namespace std;

int remDupl(int arr[],int n){
    int res=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}

// Here the elements are considered and are placed at their exact positions.
// i=1; arr[]={10,20,20,30,30,30} res=2
// The current element is compared with the last element if it is present in the array then we can simply say that 
// We can exclude that particular element and can move to the next case.