#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

int solve(vector<int> &arr,int n){
	int profit = 0;
    int min_value = INT_MAX;
    int max_profit = 0;
    for(int i=0;i<arr.size();i++){
        min_value = min(min_value,arr[i]);
        if(arr[i]>min_value){
            profit = arr[i]-min_value;
            max_profit = max(max_profit,profit);
        }
    }
    return max_profit;
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif

	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr;

		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}

		int ans = solve(arr,n);
		cout<<ans<<endl;
	}

	return 0;
}