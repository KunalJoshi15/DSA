#include<iostream>
#include<string.h>

using namespace std;

int memo[100000];

int fib(int n){
	if(memo[n]==-1){
		// if the value is not already computed then we compute it again.
		int res;

		if(n==0||n==1) return n;
		else{
			res = fib(n-1)+fib(n-2);
		}

		memo[n] = res;
	}
	return memo[n];
}

int fib_bottom_up(int n){
	int f[n+1];

	f[0] = 0;
	f[1] = 1;

	for(int i=2;i<=n;i++){
		f[i] = f[i-1]+f[i-2];
	}

	return f[n];
}

int main()
{
	int n=5;
	memset(memo,-1,sizeof(memo));

	cout<<fib(5);
}