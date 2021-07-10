#include<bits/stdc++.h>

using namespace std;
// In case of the naive approach we find all the subbarrays with the given prefix sum. 
// If the prefix sum of the larger length array is equal to the sum which is needed. 
// This can be done.
int largest(int arr[],int n,int sum)
{
    unordered_map<int,int> m;
    int pre_sum=0;
    int res = 0;
    for(int i=0;i<n;i++){
        pre_sum += arr[i];
        if(pre_sum==sum){
            res = i+1;
        }
        if(m.find(pre_sum)==m.end()){
            m.insert({pre_sum,i});
        }

        if(m.find(sum-pre_sum)!=m.end()){
            res = max(res,i-m[pre_sum-sum]);
        }
    }
    return res;
}

int main()
{
    // Here we can use the same concept of the prefix_sum having a certain value.
}