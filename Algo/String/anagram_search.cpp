#include<bits/stdc++.h>
#define CHAR 256;
using namespace std;

bool areAnagram(string &pat,string &txt,int i){
	// Here we have  simply defined an array of characters which will be considered whether it is the anagram or not.

	int count[CHAR] = {0};
	for(int j=0;j<txt.length();j++){
		count[pat[i]]++;
		count[txt[i+j]]--;
	}

	for(int j=0;j<CHAR;j++){
		if(count[j]!=0) return false;
	}
	return true;
}

bool isPresent(string &txt,string &pat)
{ 
	// This particular solution is similar to checking whether the currently existing index is the anagram of the previous one.
	// The other part of the code is simply checking whether a particular string is anagram or not.
	int n = txt.length();
	int m = pat.length();

	for(int i=0;i<=n-m;i++){
		if(areAnagram(pat,txt,i)){
			return true;
		}
	}
	return false;
}

bool areSame(int CT[CHAR],int CP[CHAR]){
	for(int i=0;i<CHAR;i++){
		if(CT[i]!=CP[i]){
			return false;
		}
	}
	return true;
} 

bool anagramSearchOptimized(string &txt,string &pat){
	int CT[CHAR]={0};
	int CP[CHAR]={0};
	// This operations
	for(int i=0;i<pat.length();i++){
		// HEre we are incrementing the count of the character map for the text in particular.
		CT[txt[i]]++;
		CP[pat[i]]++;
	}

	for(int i=pat.length();i<txt.lengt();i++){
		if(areSame(CT,CP)){
			return true;
		}
		CT[txt[i]]++;
		CT[txt[i-pat.length()]]--;
	}
	return false;
}

int main()
{

}