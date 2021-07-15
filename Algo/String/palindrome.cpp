#include<bits/stdc++.h>

using namespace std;

bool isPal(string str){
    int begin =0;
    int end = str.length()-1;

    while(begin<end){
        if(str[begin]!=str[end]){
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    // The naive approach to solve this particular problem is that we reverse the current string and then check whether it is equal to the string or not.
    // The other way is to use two pointers one starts from the starting while the other one starts from the end.
}