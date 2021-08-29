#include<bits/stdc++.h>

using namespace std;

void largestK(int *arr,int n,int k){
	deque<int> dq;

	for(int i=0;i<k;i++){
		while(dq.empty()==false and arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(int i=k;i<n;i++){
		cout<<arr[dq.front()]<<" ";

		while(dq.empty()==false and dq.front()<=i-k){
			dq.pop_front();
		}

		while(dq.empty()==false and arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout<<arr[dq.front()]<<" ";
}

int main()
{
	int arr[] = {1,2,1,2,4,5,3,2};
	int n = sizeof(arr)/sizeof(int);
	int k = 3;

	largestK(arr,n,k);
}