#include<bits/stdc++.h>

using namespace std;

string remove_consecutive(string s){
    if(s.length()==0) return "";
    if(s.length()==1) return s[0]+"";
    string smallAns=remove_consecutive(s.substr(1));
    if(s[0]!=smallAns[0]){
        return s[0]+smallAns;
    }
    return smallAns;
}

int main(){
    int test;
    cin>>test;
    cout<<endl;
    while(test--){
    string s;
    getline(cin,s);
    string output= remove_consecutive(s);
    int sum=0;
    
    for(int i=0;i<output.size();i++){
        sum=sum+(output[i]-'0');
    }
    
    cout<<sum;
    }
}