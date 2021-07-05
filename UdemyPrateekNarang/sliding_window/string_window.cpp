#include<bits/stdc++.h>

using namespace std;
/*
In case of the string window technique. We create the one frequency map for the solution string and we even create a map for
the other string as well find the window size that will be needed to represent the string.
*/

string stringWindow(string s1,string s2){
    int FP[256] = {0};
    int FS[256] = {0};
    int start_idx = -1;
    int min_so_far = INT_MAX;
    for(int i=0;i<s2.length();i++){
        FP[s2[i]]++;
    }
    // Sliding Window Algorithm
    int window_size=0;
    int cnt=0;
    int start=0;
    for(int i=0;i<s1.length();i++){
        //expand the window by including current character;
        char ch = s1[i];
        FS[ch]++;
        // Frequency of the chracter in the window is larger than the frequency of that character in the pattern then that particular character is not useful to us.
        // Count how many characters have een matched till now (string and pattern)
        if(FP[ch]!=0 and FS[ch]<=FP[ch]){
            cnt++;
        }

        //ANother things
        // If all the characters of the pattern are found in the current window then you can start contracting.
        if(cnt==s2.length()){
            // We will start contracting the unwanted characters from the starting point.
            // Unwanted characters are one which are not present in the pattern and those whose frequencies are less pattern.
            while(FP[s1[start]] or FS[s1[start]]>FP[s1[start]]){
                FS[s1[start]]--;
                start++;
            }

            //Note the window size;
            window_size = i-start+1;
            if(window_size<min_so_far){
                min_so_far = window_size;
                start_idx = start;
            }
        }
    } 
    if(start_idx==-1) {
        return "No window found";
    }
    return s1.substr(start_idx,min_so_far);
}

int main()
{
    string s1="hello";
    string s2="oel";
    string solution = stringWindow(s1,s2);
}