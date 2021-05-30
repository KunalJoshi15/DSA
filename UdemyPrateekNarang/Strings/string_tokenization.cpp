#include<bits/stdc++.h>

using namespace std;


int main(){
    string input;
    getline(cin,input);
    // Create a string stream object

    stringstream ss(input);
    // This can also be used for tokenizing the input as per our requirement.
    //>> and << operators-> Inside the stringstream we have the left shift and the right shift operations that can help us in reading the data which is required by us.
    string token;
    vector<string> tokes;
    while(getline(ss,token,' ')){
        tokes.push_back(token);
    }

    for(auto itr:tokes){
        cout<<itr<<endl;
    }
}