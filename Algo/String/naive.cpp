#include<bits/stdc++.h>

using namespace std;
// In case of the naive pattern searching algorithm we have a pattern we make the comparisions to the index from starting to the last.
// These all comparisons are always made as per our requirement.
void findPatternIndex(string &s,string &p){
	// We are provided with the string as well as the pattern.
	// The time complexity of this particular algorithm is O(n-m+1)*m -> There are few algorithms that are better than this.
	for(int i=0;i<=s.size()-p.size();i++){
		int j;
		for(j=0;j<p.size();j++){
			if(s[i+j]!=p[j]){
				break;
			}
		}
		if(j==p.size()){
			cout<<i<<" ";
		}
	}
	return;
}
// This particular naive algorithm can be improved to huge extent if all the elements which are present are distinct.
// The improved naive pattern searching algorithm works in the same way as the other algorithms.

void findPatternIndex2(string &s,string &p){
	// Here the case will be when i and j are equal.
	int m = s.size();
	int n = p.size();

	for(int i=0;i<m;i++){
		int j;
		for(j=0;j<n;j++){
			if(s[i+j]!=p[j]){
				break;
			}
		}
		
		if(j==p.size()){
			cout<<i<<" ";
		}if(j==0){
			i++;
		}else{
			i = i+j;
		}

	}
}

int main()
{
	string s;
	cin>>s;
	findPatternIndex(s);
}