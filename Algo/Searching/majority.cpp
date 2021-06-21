#include<bits/stdc++.h>

using namespace std;

int findMajority(int *arr,int n){
    int count=1,res=0;
    // Find the element which is eligible of becoming the majority element.
    for(int i=0;i<n;i++){
        if(arr[res]==arr[i]){
            count++;
        }else{
            count--;
        }
        if(count==0){
            res=i;
            count=1;
        }
    }
    // The element which is in the position res is eligible of becoming the majority element if this particular element is not a majority element then there isn't any majority element present in the array.
    count=0;
    for(int i=0;i<n;i++){
        if(arr[res]==arr[i]) count++;
    }
    if(count>n/2) return arr[res];
    return -1;
}

int main()
{
    int arr[] = {1,2,2,2,2,3,4,5,2,1,2,3,5,6};
    int majority = findMajority(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<majority;
}