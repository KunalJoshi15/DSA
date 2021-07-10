/*
In this particular program we want to find the subarray which has the values 0's and 1's.
We need to find the longest subarray following this.
*/

#include<bits/stdc++.h>

using namespace std;
// The naive approach to solve this particular prblem is to consider all the subarrays possible. And find the size of the one which has the max number of equal 0's and 1's.
int largest(int arr[],int n){
    unordered_map<int,int> m;
    int res=0;
    int pre_sum=0;
    for(int i=0;i<n;i++){
        pre_sum += arr[i];
        if(pre_sum==0){
            res = i+1;
        }
        if(m.find(pre_sum)==m.end()){
            m.insert({pre_sum,i});
        }
        if(m.find(pre_sum)!=m.end()){
            if(res<i-m[pre_sum+n]){
                res = i-m[pre_sum+n];
            }
        }
    }
    return res;
}
int main()
{
    int arr[] = {1,0,1,1,1,0,0};
    // If there are only one's or only zeros then there isn't any particular subarray having those properties.
    // There is a small tweak that can be used to solve this particular problem in the tweak we will replace all the 0's with -1. and now the problem is same as finding the max length subarray with sum as 0.
}