#include<bits/stdc++.h>

using namespace std;
// The naive approach can be used we consider all the pairs and find a pariticular pair with the target sum if it is present or not.
// There is a better approach than this in which we can sort the elements of the array which is present.
bool isPair(int arr[],int n,int sum){
    unordered_set<int> h;
    for(int i=0;i<n;i++){
        if(h.find(sum-arr[i])!=h.end()){
            return true;
        }
        else{
            h.insert(arr[i]);
        }
    }
    // In this particular approach we will be inserting the values one after the other.
    return false;
}

int main()
{
    // The best approach to solve this particular quesiton is to consider the current element and try to find its complement in the hash set.
    // If the complement for the particular element is present then we can simply say that the element exists
}