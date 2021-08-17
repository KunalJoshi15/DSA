#include<bits/stdc++.h>

using namespace std;

void nextGreater(int *arr,int n){
	for(int i=0;i<n;i++){
		int j;
		for(j=i+1;j<n;j++){
			if(arr[j]>arr[i]){
				cout<<arr[j]<<" ";
				break;
			}
		}
		if(j==n){
			cout<<-1<<" ";
		}
	}
}

vector<int> nextGreater1(int *arr,int n){
	vector<int> v;
	stack<int> stk;
	stk.push(arr[n-1]);

	for(int i=n-1;i>=0;i--){
		while(stk.empty()==false and arr[i]>=stk.top()){
			stk.pop();
		}
		int max = stk.empty()?(-1):stk.top();
		v.push_back(max);
		stk.push(arr[i]);
	}
	reverse(v.begin(),v.end());
	return v;
}

int main()
{
	int arr[] = {5,3,2,3,1,2,3,7};
	int n = sizeof(arr)/sizeof(int);
	nextGreater(arr,n);
	cout<<endl;
	vector<int> solution = nextGreater1(arr,n);
	for(int x:solution){
		cout<<x<<" ";
	}
}