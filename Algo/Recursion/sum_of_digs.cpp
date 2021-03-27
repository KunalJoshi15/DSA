#include<bits/stdc++.h>

using namespace std;

int fun(int a){
    if(a==0) return 0;
    int smallAns = fun(a/10);
    return smallAns+a%10;
}

int main(){
    int a;
    cin>>a;
    int sum = fun(a);
    cout<<sum;
}