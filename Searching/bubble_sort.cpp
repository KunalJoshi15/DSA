#include<bits/stdc++.h>

using namespace std;

int binary_iterative(vector<int> &v){
    int low = 0;
    int high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==x) return mid;
        if(v[mid]>x) high=mid-1;
        if(v[mid]<x) low=mid+1; 
    }
}
int binary_recursive(vector<int> &v,int low,int high,int x){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(v[mid]==x) return mid;
    if(v[mid]>x) return binary_recursive(v,low,mid-1,x);
    if(v[mid]<x) return binary_recursive(v,mid+1,high,x);
}

int main(){
    vector<int> v{4,2,3,54,1,23,2,34,2,1,2,4,56,6,4};
    int x;
    cin>>x;
    int first = binary_iterative(v,x);
    int second = binary_recrusive(v,0,v.size()-1,x);
}