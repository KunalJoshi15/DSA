#include<bits/stdc++.h>

using namespace std;
int length(char *ch){
    if(ch[0]=='\0') return 0;
    int smallString = length(ch+1);
    return 1+smallString;
}

void remove_x(char *ch){
    if(ch[0]=='\0') return;
    if(ch[0]!='x'){
        remove_x(ch+1);
    }
    else{
        int i=1;
        for(;ch[i]!='\0';i++){
            ch[i-1]=ch[i];
        }
        ch[i-1]=ch[i];
        remove_x(ch);
        // Here ch+1 is not done because we have already reduced the size of the string itself. Therefore no need to do that.
    }
}

int main()
{
    char ch[100];
    cin>>ch;
    int a = length(ch);
    cout<<a<<" ";
    remove_x(ch);
    cout<<ch<<" ";
    a=length(ch);
    cout<<a<<" ";
}