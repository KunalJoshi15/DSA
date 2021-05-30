#include<iostream>
#include<string>

using namespace std;

int main(){
    // char s[1000] = {'1','2','a','\0'}
    // These are used for the representation of the strings. This isn't the most decent way of representation of the strings.
    string s;
    getline(cin,s,'.');
    for(char ch:s){
        cout<<ch<<",";
    }
    // This will take all the elements of the array and then will store them in characters and then print them
    // If there are multiple strings present then we can simply use the vector of strings.
    
    string p="This is the best one of the course that we have for the compeitive programming";
    cout<<p.find("is");
    int i = p.find("asd");
    // If we have provided a string to the find funciton then we will get -1 value.

    cout<<s<<endl;

    // Here the third parameter represents the delimeter when the input taking is to be stopped.
    // This can be used for creating the dynamic sized strings.
}