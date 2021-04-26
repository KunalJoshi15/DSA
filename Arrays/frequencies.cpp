#include<bits/stdc++.h>

using namespace std;

int main(){
    map<int,int> mp;
    int arr[] = {2,2,3,1,2,3,54,6,5};
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        mp[arr[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        cout<<i->first<<" "<<i->second;
    }
}