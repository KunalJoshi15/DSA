#include<bits/stdc++.h>

using namespace std;
/*
There are two approaches in which we can find the k largest element.
1) In case of the naive approach we will be simply sorting the array and then removing elements one after the other.
2) In case of the more efficient approach we will be mantaining the min heap of k elements and if an element appears which is smaller than the current min of the heap then we will be simply replacing that particular element. 
*/

bool comp(int &a,int &b){
	return a>b;
}

void naiveKLargest(int arr[],int n,int k){
	sort(arr,arr+n,comp);

	for(int i=0;i<k;i++){
		cout<<arr[i]<<endl;
	}
}

void effKLargest(int arr[],int n,int k){
	priority_queue<int,vector<int>,greater<int>> pq;

	for(int i=0;i<k;i++){
		pq.push(arr[i]);
	}

	for(int i=k;i<n;i++){
		int smallest = pq.top();
		if(smallest<arr[i]){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	while(pq.empty()==false){
		cout<<pq.top()<<endl;
		pq.pop();
	}
}

int main()
{
	int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;
	// naiveKLargest(arr,size,k);
	effKLargest(arr,size,k);
}