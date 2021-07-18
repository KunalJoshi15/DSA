#include<bits/stdc++.h>

using namespace std;
/*
Here in this particular problem we want to find the longest possible substring with all distinct characters possible.

*/
// NAIVE SOLUTION TO THIS PARTICULAR PROBLEM IS AS FOLLOWS.
bool areDistinct(string str,int i,int j){
	vector<bool> visited(256,false);

	for(int k=i;k<=j;k++){
		if(visited[str[k]]){
			return false;
		}
		visited[str[k]]=true;
	}
	return true;
}


int largestDistinct(string &str){
	int n = str.length();
	int res=0;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(areDistinct(str,i,j)){
				res = max(res,j-i+1);
			}
		}
	}
	return res;
}
// O(n^2) solution. In this better solution we will not doing the comparison afterwards.
// There will be a visited array created for the current character only.
int largestDistinctbet(string &str){
	int n = str.length();
	int res=0;

	for(int i=0;i<n;i++){
		vector<bool> visited(256);
		for(int j=i;j<n;j++){
			if(visited[str[i]]==true){
				break;
			}
			else{
				res = max(res,j-i+1);
				visited[str[i]]=true;
			}
		}
	}
	return res;
}
// The best solution to this particular problem is O(n) it is not very intuitive solution so bear with it.
int longestDistinct(string str){
	int n = str.length();
	int res=0;
	int i=0;
	// This is an elegant approach to do its questions.
	// All the values which are present in the vector are initialized to -1.
	vector<int> prev(256,-1);
	for(int j=0;j<n;j++){
		i = max(i,prev[str[j]]+1);
		int maxEnd = j-i+1;
		res = max(res,maxEnd);
		prev[str[j]]=j;
	}
	return res;
}

int main()
{
	string str = "geeksforgeeks"; 
	int len = longestDistinct(str); 
	cout << "The length of the longest distinct characters substring is "<< len; 
	return 0;
}