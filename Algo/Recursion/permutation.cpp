#include<bits/stdc++.h>

using namespace std;

void permute(string s,int i=0){
    if(i==s.size()-1) {
        cout<<s<<" ";
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        permute(s,i+1);
        //This second swap method is the backtracking solution as we will be brining the terms back.
        swap(s[i],s[j]);
    }
}

int main(){

}