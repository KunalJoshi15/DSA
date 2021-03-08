#include<bits/stdc++.h>

using namespace std;

string remove_x(string s,int size,int i){
    string sol="";
    if(size==0) return sol;
    if(i==size) return sol;
    string smallAns = remove_x(s,size,i+1);
    if(s[i]!='x'){
        smallAns=s[i]+smallAns;
    }
    return smallAns;
}

int main(){
    string s;
    cin>>s;
    string q=remove_x(s,s.size(),0);
    cout<<q;   
}