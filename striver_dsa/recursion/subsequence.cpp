#include<bits/stdc++.h>
#define ll long long int;
using namespace std;
vector<vector<int>> demo;
vector<int> sm;

void findsubs(int *arr,int n){
	if(n<0){
		for(int x:sm){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	//picking the element
	sm.push_back(arr[n]);
	findsubs(arr,n-1);
	sm.pop_back();
	findsubs(arr,n-1);
}
/*
 pick and not pick strategy is used we add the element as per our requirement and then we remove when the element is not needed.
*/

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(int);
	findsubs(arr,n-1);

	return 0;
}
/*
Here  subsequence is when we  pick an element and we can even omit an element as per our requirement.
*/