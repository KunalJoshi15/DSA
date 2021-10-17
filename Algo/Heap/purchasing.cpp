#include<bits/stdc++.h>

using namespace std;

int purchaseNaive(int arr[],int n,int sum){
	sort(arr,arr+n);
	int res=0;

	for(int i=0;i<n;i++){
		if(arr[i]<=sum){
			sum = sum-arr[i];
			res++;
		}else{
			break;
		}
	}
	return res;
}

// using heaps
int purchaseEff(int arr[],int n,int sum){
	priority_queue<int,vector<int>,greater<int>> pq;

	int res = 0;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}

	for(int i=0;i<n;i++){
		if(pq.top()<=sum){
			sum -= pq.top();
			pq.pop();
			res++;
		}
		else{
			break;
		}
	}
	return res;
}

int main()
{
	int arr[] = {1,12,5,111,200}; 
	int sum=10;
	int n = sizeof(arr)/sizeof(int);

	cout<<purchaseEff(arr,n,sum);
}
/*
There is O(n log n) approach in which sorting is performed.
heaps are used.
*/