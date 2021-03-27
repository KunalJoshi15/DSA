#include<bits/stdc++.h>

using namespace std;

bool palindrome(string a,int start,int end){
    if(start==end||start+1==end) return true;

    if(a[start]!=a[end-1]){return false;}
    palindrome(a,start+1,end-1);
}

int main(){
    string a;
    cin>>a;
    if(palindrome(a,0,a.size())) cout<<"String is palindrome";
    else cout<<"String is not palindrome";
}