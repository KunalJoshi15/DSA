#include<bits/stdc++.h>

using namespace std;
// Naive solution to this paroblem. We check the repetition for all the characters one by one therefore this particular solution is O(n^2)


// The other approach will be create a frequency map for all the characters which are present in the array.
const int CHAR=256;

int leftmost(string &str1){
    // The count for  all the characters are initialized to 0.
    int count[CHAR]={0};
    // works in linear time.
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]>1){
            return i;
        }
    }
    return -1;
}

int leftMost1(string &str1){
    int count[CHAR]={0};
    fill(count,count+CHAR,-1);
    int res = INT_MAX;

    for(int i=0;i<str.length();i++){
        int fi = count[str[i]];
        if(fi==-1){
            fIndex[str[i]]=i;
        }
        else{
            res = min(res,fi);
        }
        // This will contain the smallest value of the repeating character.
    }
    return res==INT_MAX?-1:res;
}
//Here we are trying to find the character which is occuring at the leftmost position in the array.
// For this particular relation we will be maintaining a vector of bool. It will tell us whether a particular character has occured till now or not.
int leftMost3(string &str) 
{
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1;
    // Start from the last character.
    // We will go backwards if the last character is repeating then we will save in this character.
    for(int i=str.length()-1;i>=0;i--){
        // from last we are checking the character if there is one more character being found with the repeating values then the index of the result that we have obtained gets changed.
        if(visited[str[i]])
        res=i;
        else
        visited[str[i]]=true;
    }
    
    return res;
}

int main()
{

}