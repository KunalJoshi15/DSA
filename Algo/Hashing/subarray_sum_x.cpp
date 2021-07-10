#include<bits/stdc++.h>

using namespace std;

bool isSum(int arr[],int n,int sum){
    unordered_set<int> s;
    // This particular procedure is used to find whether there is a subarray with the sum which is less than the current sum.

    int pres_sum=0;
    // we are finding the prefix sum after considering all the elements if prefix_sum-sum already exists there in the hashmap then there is a particular place with sum 0.
    for(int i=0;i<n;i++){
        if(pres_sum==sum){
            return true;
        }
        pres_sum+=arr[i];
        if(s.find(pres_sum-sum)!=s.end()){
            return true;
        }
        // Otherwise we will be simply inserting the value to the location which is specified.
        s.insert(pres_sum);
    }
    return false;
}

int main()
{
    int arr[]  = {5,8,6,13,3,-1};
    // For each of the 
    // Check the value of the current prefix sum. Find whether the subtraction of it is already present in the hashmap.
}