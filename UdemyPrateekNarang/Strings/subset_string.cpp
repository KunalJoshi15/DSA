#include<bits/stdc++.h>

using namespace std;

int main(){
    // The worst case solution will be considering each sub string and checking whether it is equal to a particular string.
    // The two pointer technique works really well in this particular case.
    // Let us consider two pointers. one pointing to the last character of the subset string while the other one to the orignal string.
    string s;
    getline(cin,s);
    string sub;
    getline(cin,sub);
    int i=s.size()-1;
    int j=sub.size()-1;

    while(i!=-1){
        if(s[i]==sub[j]){
            i--;
            j--;
        }
        else{
            i--;
        }
        if(j==-1){
            break;
        }
    }
    if(j==-1){
        cout<<"YES";
    }
}