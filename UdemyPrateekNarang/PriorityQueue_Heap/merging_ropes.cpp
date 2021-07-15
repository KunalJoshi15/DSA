#include<bits/stdc++.h>

using namespace std;
bool comp(int a,int b){
    return a<b;
}

int mergingRopes(int arr[],int n){
    priority_queue<int,vector<int>,comp> h(arr,arr+n);
    // Here we have placed all the elements into the prirority queue. This is the creation of the min heap.
    int ans=0;
    while(!h.empty()){
        int a = h.top();
        h.pop();
        int b = h.top();
        h.pop();
        int c = a+b;
        ans += c;
        h.push(c);
    }
    return ans;
}

int main()
{
    int arr[] = {2,1,3,4,1,2,3,5,6,2};
    int n = sizeof(arr)/sizeof(int);
}