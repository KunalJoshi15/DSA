#include<bits/stdc++.h>

using namespace std;

void remove_duplicates(char *ch){
    if(ch[0]=='\0') return;
    if(ch[0]==ch[1]){
        int i=1;
        for(;ch[i]!='\0';i++){
            ch[i-1]=ch[i];
        }
        ch[i-1]=ch[i];
        remove_duplicates(ch);
    }else{
        remove_duplicates(ch+1);
    }
}

int main(){
    char ch[100];
    cin>>ch;
    remove_duplicates(ch);
    cout<<ch;
}