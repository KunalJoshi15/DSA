#include<bits/stdc++.h>

using namespace std;

void fun(int n){
    if(n==0) return;
    fun(n/2);
    cout<<n%2;
}

int main(){
    int a;
    cin>>a;
    fun(a);
}
// We will be then printing the remainders in the reverse order in which we get those.