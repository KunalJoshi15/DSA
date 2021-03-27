#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    string output=s[0]+"";
    for(int i=1;i<s.length();i++){
        if(s[i-1]==s[i]){
            continue;
        }
        else{
            output=output+s[i];
        }
    }
    cout<<output<<endl;
}