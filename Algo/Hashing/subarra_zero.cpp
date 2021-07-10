#include<bits/stdc++.h>

using namespace std;

bool is0Subbary(int arr[],int n){
    unordered_set<int> h;
    int pre_sum=0;

    for(int i=0;i<n;i++){
        pre_sum += arr[i];
        // If the same perfix sum exists again then we simply return true.
        if(h.find(pre_sum)!=h.end()){
            return true;
        }
        if(pre_sum==0)
            return true;
        h.insert(pre_sum);
    }
    return false;
}

int main()
{
    // Finding whether there is a subarray present with a particular sum or not. we will be using an elegant solution which is in place.
    // We will be finding the prefix sum of the terms and if it is not present in the hashset then we will simply add that to the hashset.

}