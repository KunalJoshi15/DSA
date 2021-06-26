#include<bits/stdc++.h>

using namespace std;

void findSubsets(string s,string output,int i,int n){
	if(i==n){
		cout<<output;
		output="";
	}
	findSubsets(s,output+s[i],n,i+1);
	findSubsets(s,output,n,i+1);
}

int main()
{
	string s = "abc";
	findSubsets(s,"",0,s.size()-1);
}