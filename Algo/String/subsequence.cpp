#include<bits/stdc++.h>

using namespace std;

bool isSubSeq(string s1,string s2,int n,int m){
    int j=0;
    for(int i=0;i<n and j<m;i++){
        if(s[i]==s[j]){
            j++;
        }
    }
    return j==m;
}
// Time complexity if O(m+n)
bool rec(string s1,string s2,int n,int m){
    if(m==0) return true;
    if(n==0) return false;

    if(s1[n-1]==s2[m-1]) return rec(s1,s2,n-1,m-1);
    else return rec(s1,s2,n-1,m);
}

int main()
{

}