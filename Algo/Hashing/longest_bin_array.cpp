#include<bits/stdc++.h>

using namespace std;

int largestCommon(int arr1[],int arr2[],int n){
    int temp[n];

    for(int i=0;i<n;i++){
        temp[i] = arr1[i]-arr2[i];
    }
    unordered_map<int,int> m;
    // Here we will be finding the longest subarray with a given sum.
    int pre_sum=0;
    int res=0;
    // This particular problem is simply reduced to finding of the subarray with 0 sum.
    for(int i=0;i<n;i++){
        pre_sum += arr[i];
        if(pre_sum==0){
            res++;
        }
        if(m.find(pre_sum)==m.end()){
            m.insert({pre_sum,i});
        }

        if(m.find(pre_sum)!=m.end()){
            res = max(res,i-m[pre_sum]);
        }
    }
}

int main(void)
{
    int arr1[] = {0,1,0,0,0,0};
    int arr2[] = {1,0,1,0,0,1};
    int n = sizeof(arr)/sizeof(int);
    int len = largestCommon(arr1,arr2,n);
}