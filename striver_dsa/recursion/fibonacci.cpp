#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

int fibo(int n){
	if(n==0 || n==1) return 1;

	return fibo(n-1)+fibo(n-2);
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int n=5;

	cout<<fibo(n);

	return 0;
}