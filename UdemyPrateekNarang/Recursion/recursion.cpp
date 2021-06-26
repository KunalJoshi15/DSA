#include<bits/stdc++.h>

using namespace std;

void goHome(int x){
	if(x==10) cout<<"You have reached Home";
	x = x+1;
	// The base case for this particular problem will be that we are already there at home.
	// Recursion basically work in a way that we assume that we have the answer to the smaller problem. We append our current value to it in order to obtain the last result.
	goHome(x+1);
}

int main(){
	int x=1;
	goHome(x);
}