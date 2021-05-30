#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    char input[1000];
    cin.getline(input,1000);
    //strtok()
    cout<<strtok(input," ");
    // In the first strtok call we will be passing the input and on the subsequent funciton call we will be passing NULL as the first parameter.
    // This function will particulary return us the first string that is before the function itself.
    // This function strtok maintains the string in the internal state.
    return 0;
}