#include<bits/stdc++.h>

using namespace std;


int main(){
    int arr[4];
    for(int i=0;i<4;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    int rhs;
    cin>>rhs;
    sort(arr,arr+4);
    int sol = solution(arr,rhs);
}