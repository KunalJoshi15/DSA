#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n=8;
	int s=0;
	int e = n;
	int ans=-1;
	// This will be finding the decimal part of the root that we are calculating.
	// For the part which is after the decimal we will have to check linearly. The complexity of that part of the code is very small but.
	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid==n){
			return mid;
		}else if(mid*mid<n){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	float m = .1;
	for(int i=1;i<=p;i++){
		while(ans*ans<=N){
			ans = ans+inc;
		}
		// Take one step back
		ans = ans-inc;
		inc = inc/10;
	}
}
