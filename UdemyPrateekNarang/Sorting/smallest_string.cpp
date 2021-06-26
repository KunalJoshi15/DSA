#include<bits/stdc++.h>

using namespace std;

/*
In the smallest string problem we need to print the smallest string that is possible lexicographically.
Here we can use our own custom comparator.
*/
bool cmp(string s1,string s2){
	return s1+s2<s2+s1;
}

string smallestString(string s[],int n){
	sort(s,s+n,cmp);
	return s;
}

int main(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		string p;
		cin>>p;
		s[i]=p;
		cout<<endl;
	}
	string smallest = smallestString(s,s.length());
}