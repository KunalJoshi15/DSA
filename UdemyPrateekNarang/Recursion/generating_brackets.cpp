#include<bits/stdc++.h>

using namespace std;

void generateBrackets(int n,int open,int close,string output){
	if(close==2*n){
		cout<<output;
		return;
	}
	if(open<n){
		// Here the mistake that poeple might make is output += "("
		generateBrakcets(n,open+1,close,output+"(");
		// If output is specified in the different position then we will simply have to pop it. output.pop_back()
	}
	if(close<open){
		// The above case which is being mentioned is followed here as well.
		generateBrackets(n,open,close+1,output+")");
	}
}

int main(){
	int n=4;
	generateBrackets(n,0,0,"");
}