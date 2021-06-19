#include<bits/stdc++.h>

using namespace std;
// In case of the brute force method.
// All the substring are checked and we store the one which is largest without any repeating characters.
// We will consider the current character if it is not already present then we will add that character.
// If not part of the window then expand the current window.
// Lookup unordered_map will be used. This lookup will contain the last occurence of the current character.
string unique_strings(string s){
    unordered_map<char,int> de;
    string solution ="";
    int start=0,end=0;
    int window_len=0;
    // The max_windo_len cariable and the start_window are used to find print the elements which are the part of the max window length. 
    int max_windo_len=0;
    int start_window=-1;
    while(end<s.length()){
        char ch = s[end];
        // If it is inside hashmap
        if(de.count(ch) and de[ch]>=start){
            start = de[ch]+1;
            window_len = end-start; //Excluding current character.
        }
        de[ch] = end;
        window_len++;
        end++;
        // Update max_window_len
        if(window_len>max_windo_len){
            max_windo_len = window_len;
            start_window = start;
        }
    }
    return s.substr(start_window,max_windo_len);
}
// The current character that we are viewing is added always into our string.
int main(){
    string s = "prateekbhaiya";
    string unique  = unique_strings(s);
}