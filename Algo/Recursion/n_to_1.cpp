#include<bits/stdc++.h>

using namespace std;

void fun(int a){
    if(a==0) return;
    cout<<a;
    fun(a-1);
    // FOR THE 1 to n print the values after the function call.
}

int main(){
    int a;
    cin>>a;
    fun(a);
}