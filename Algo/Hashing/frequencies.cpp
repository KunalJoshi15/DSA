#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {1,2,3,1,2,5,6,4,5,2,34,6,423,234,34,2};
    int n = sizeof(arr)/sizeof(int);
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}