#include<bits/stdc++.h>

using namespace std;
// In case of the naive approach we will run two loops for the current element we will check whether the element with the same value is present in the left side of the array.
// Simply unordered_set can be used set can be removed. Simply return the size of the set.
int main()
{
    int arr[] = {1,3,5,1,2,3,5,7,8,6,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    for(auto it=m.begin();it!=m.end();it++){
        if(it->second==1){
            cout<<it->first<<" ";
        }
    }
}