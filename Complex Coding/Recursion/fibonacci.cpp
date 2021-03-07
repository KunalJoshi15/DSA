#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n==0||n==1) return n;
    int small1=fibonacci(n-1);
    int small2=fibonacci(n-2);
    return small1+small2;
}

int main(){
    // If there are multiple recursive calls then there will be multiple base cases.
    int n;
    cin>>n;
    cout<<fibonacci(n);
}