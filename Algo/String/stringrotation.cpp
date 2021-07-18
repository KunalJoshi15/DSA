#include<bits/stdc++.h>

using namespace std;

bool rotation(strins &s1,string &s2)
{
	// s1 and s2 are appended and then we find the pattern in the string.
	if(s1.length()!=s2.length()) return false;
	return ((s1+s2).find(s2)!=string::npos);
}

int main()
{
	// we are provided with two strings we need to find whether a particular stirng is the rotation of the other string.
	string s1 = "ABCD";
	string s2 = "CDAB";
	bool solution = rotation(s1,s2);
	if(solution){
		cout<<"PATTERN IS FOUND";
	}
	else{
		cout<<"PATTERN IS NOT FOUND";
	}
	return 0;
}