#include<bits/stdc++.h>

using namespace std;
// The naive solution to this particular problem is we check the elements which are to the left of the current element. 
// If no element is greater then print -1.
void printGreater(int arr[],int n){
	for(int i=0;i<n;i++){
		int j;
		for(j=i-1;j>=0;j--){
			if(arr[j]>arr[i]){
				cout<<arr[i]<<" ";
				break;
			}
		}
		if(j==-1){
			cout<<"-1 ";
		}
	}
	// O(n^2) will be the solution to the problem.
}

void printGreater1(int arr[],int n){
	stack<int> s;
	s.push(arr[0]);
	// This is simply a variation of the stock span 
	for(int i=0;i<n;i++){
		while(s.empty()==false and s.top()<=arr[i]){
			s.pop();
		}
		int pg = s.empty()?-1:s.top();
		cout<<pg<<" ";
		s.push(arr[i]);
	}
}

int main() 
{ 
    int arr[]={20,30,10,5,15};
    int n=5;
    printGreater1(arr,n);
    return 0; 
}
// For the first element in particular we can print the span directly.