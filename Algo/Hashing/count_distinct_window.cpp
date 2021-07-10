#include<bits/stdc++.h>

using namespace std;
// In case of the naive approach we can simply run the outer loop n-k times so that we can consider all the windows which are present.
// The one loop inside the windows is to consider the first element while the other one is to find whether the element is seen for the window or not.
// The idea which can be used is of hashing in the hashing concept we will be maintaining the count of the elements which are present in the current window.
// here we will be mainly processing the item which is being removed from the current window and the item that is being added to the current window.
void countDistinct(int arr[],int n,int k){
    unordered_map<int,int> m;
    for(int i=0;i<k;i++){
        m[arr[i]]++;
    }
    cout<<m.size();
    for(int i=k;i<n;i++){
        if(m[arr[i-k]]==1){
            m.erase(m.find(arr[i-k]));
        }
        else{
            m[arr[i-k]]--;
        }
        m[arr[i]]++;
        cout<<m.size();
    }
}

int main()
{
    // In this particular problem we want to find the count of the distinct elements which are present in the array window.
    // For all the windows which are present this needs to be determined.
    int arr[] = {10,20,10,10,30,40};
    int n = sizeof(arr)/sizeof(int);
    int k = 4;
    countDistinct(arr,n,k);
}