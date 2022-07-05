#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void func(int ind,int sum,vector<int> &arr,int N,vector<int> &subset){
	if(ind==N){
		subset.push_back(sum);
		return;
	}

	func(ind+1,sum+arr[ind],arr,N,subset);
	func(ind+1,sum,arr,N,subset);
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif

	// subset sum is the sum of all the values.
	// all the subsets needs to be returned therefore the worst case space
	//complexity is O(2^n)
	vector<int> sumSubset;
	func(0,0,arr,N,sumSubset);
	sort(sumSubset.begin(),sumSubset.end());


	return 0;
}