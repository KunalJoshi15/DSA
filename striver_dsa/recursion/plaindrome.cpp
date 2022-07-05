#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

bool isPalin(string &s,int i,int r){
	if(i>=r){
		return true;
	}
	if(s[i]==s[r]){
		return isPalin(s,i+1,r-1);
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	string s;
	cin>>s;

	if(isPalin(s,0,s.size()-1)){
		cout<<"Palindrome";
	} else {
		cout<<"Not Palindrome";
	}
	return 0;
}