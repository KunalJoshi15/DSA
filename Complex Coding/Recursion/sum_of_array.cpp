#include<bits/stdc++.h>

using namespace std;
int sum_of_array(int* arr,int n){
    if(n==0) return 0;
    if(n==1) return arr[0];
    int smallAns = sum_of_array(arr+1,n-1);
    return arr[0]+smallAns;
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
    cout<<sum_of_array(arr,n);
}