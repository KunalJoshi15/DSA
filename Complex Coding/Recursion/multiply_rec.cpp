#include<bits/stdc++.h>
using namespace std;

int multiple(int a,int b){
    if(a==0||b==0) return 0;
    if(b==1) return a;
    int smallAns = multiple(a,b-1);
    return a+smallAns;
}

int main(){
    int a,b;
    cin>>a>>b;
    int m = multiple(a,b);
    cout<<m;
}