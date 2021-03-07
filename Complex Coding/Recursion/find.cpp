#include<bits/stdc++.h>
using namespace std;
bool find(int *arr,int x,int n){
    if(n==0) return false;
    if(arr[0]==x) return true;
    return find(arr+1,x,n-1);
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    int x;
    cin>>x;
    if(find(arr,x,n)){
        cout<<"Number is present in the array ";
    }
    else{
        cout<<"NUmber is not present in the array";
    }
}