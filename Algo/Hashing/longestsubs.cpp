#include<bits/stdc++.h>

using namespace std;
// THE NAIVE SOLUTION TO THIS PARTICULAR SUBPROBLEM USES THE CONCEPT OF SORTING. THEN WE WILL SIMPLY TRAVERSE THE ARRAY. 
// O(n log n)
int naiveSub(int arr[],int n){
    sort(arr,arr+n);
    int res = 1;
    int curr=1;

    for(int i=1;i<n;i++){
        if(arr[i]==1+arr[i-1]){
            curr++;
        }
        else if(arr[i]!=arr[i-1]){
            res = max(curr,res);
            curr=1;
        }
    }
    return res;
}

int efficientSub(int arr[],int n){
    unordered_set<int> s;

    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    // There are always 2n lookups.
    int curr=1;
    int res=1;
    for(int i=0;i<n;i++){
        int ele = arr[i];
        if(s.find(ele-1)!=s.end()){
            continue;
        }
        while(s.find(ele+1)!=s.end()){
            curr++;
        }
        res = max(curr,res);
        curr=1;
    }
}

int main()
{
    
}