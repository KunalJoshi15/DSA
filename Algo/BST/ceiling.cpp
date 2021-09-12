#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

/*
The naive approach for solving this particular problem is as follows.
*/
void printCeiling(int arr[],int n){
	cout<<-1<<" ";
	for(int i=1;i<n;i++){
		// This value will represent the postive infinite value.
		int diff = INT_MAX;

		for(int j=0;j<i;j++){
			if(arr[j]>=arr[i])
				diff = min(diff,arr[j]-arr[i]);
		}
		if(diff==INT_MAX){
			cout<<-1<<" ";
		}
		else{
			cout<<arr[i]+diff<<" ";
		}
	}
}

void printCeilingEfficient(int arr[],int n){
	cout<<-1<<" ";
	set<int> s;
	s.insert(arr[0]);

	for(int i=1;i<n;i++){
		if(s.lower_bound(arr[i])!=s.end()){
			cout<<*(s.lower_bound(arr[i]))<<" ";
		}
		else{
			cout<<-1<<" ";
		}
		s.insert(arr[i]);
	}
}

int main()
{
	int arr[] = {2,8,30,15,25,12};
	int n = sizeof(arr)/sizeof(arr[0]);
	printCeiling(arr,n);
	cout<<endl;
	printCeilingEfficient(arr,n);
}