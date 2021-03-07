#include<bits/stdc++.h>
using namespace std;
int no_of_digs(int n){
    if(n>=0&&n<=9) return 1;
    int smallAns = no_of_digs(n/10);
    return 1+smallAns;
}
int main(){
    int n;
    cin>>n;
    cout<<no_of_digs(n);
}