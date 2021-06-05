#include<bits/stdc++.h>

using namespace std;

char *mystrtok(char *str,char delim){
    // wE NEED TO IDENTIFY THE FIRST CALL OF THE FUNCTION AS PER OUR REQUIREMENT.

    static char *input = NULL;
    // This is made static because the changes which are made to the char pointer is permanent.
    // We will be creating a dynamic array as static array cannot be returned.
    if(str!=NULL){
        input = str;
    }
    if(input==NULL) return NULL;
    char *token = new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++){
        // Traverse the entire input array 
        if(input[i]!=delim){
            token[i] = input[i];
        }else{
            token[i]='\0';
            // Here incrementing the input pointer means that we are pointing to some different location.
            input = input+i+1;
            return token;
        }
    }
    //Out of the loop
    token[i]='\0';
    input=NULL;
    return token;
}

int main(){
    char s[1000];
    cin.getline(s,1000);
    char *token = mystrtok(s,' ');

    while(token!=NULL){
        cout<<token<<endl;
        token = mystrtok(NULL,' ');
    }
}

