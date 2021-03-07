#include<bits/stdc++.h>
using namespace std;

bool sorted(int* arr,int n){
    if(n==1||n==0) return true;
    if(arr[0]>arr[1]) return false;
    bool isSmallerSorted = sorted(arr+1,n-1);
    return isSmallerSorted;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    if(sorted(arr,n)){
        cout<<"Array is Sorted";
    }else{
        cout<<"Array is not sorted";
    }
    delete[] arr;
}