#include<bits/stdc++.h>
using namespace std;
int power(int a,int b){
    if(b==0) return 1;
    int smaller=a*power(a,b-1);
    return smaller;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);
}