#include<bits/stdc++.h>

using namespace std;

int subs(string s,string *output){
    if(s.empty()){
        return 1;
    }
    string smallString = s.substr(1);
    int smallStringSize = subs(smallString,output);
    for(int i=0;i<smallStringSize;i++){
        output[i+smallStringSize] = s[0]+output[i];
    }
    return 2*smallStringSize;
}

int main()
{
    string s;
    cin>>s;
    string *output = new string[1000];
    int size = subs(s,output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }
}