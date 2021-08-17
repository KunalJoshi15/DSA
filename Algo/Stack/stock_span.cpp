#include <bits/stdc++.h>
using namespace std;
//This is the naive soution to the problem.
//The span of the current element is always 1.
//from the current value of i we will go backwards to find the index where the value of j is greater than i that will represent the span of the current element.
void printSpan(int arr[],int n){
    for(int i=0;i<n;i++){
        int span=1;
        for(int j=i-1;j>=0&&arr[j]<=arr[i];j--)
            span++;
        cout<<span<<" ";
    }    
}
//Efficient Solution: Traversal from the left to right.
//If some larger element occurs then the current top then we can simply pop the current top as that will definitely not contribute to the span of the remaining elements.
void findSpan(int arr[],int n){
	stack<int> stk;
	// if the current element that we have is larger than the previous elements then we will simply ignore all the elements which are smaller than the current element.
	stk.push(0);
	cout<<"1 ";
	// From the first index. we need to find the span of the index.
	
	for(int i=1;i<n;i++){
		// We will be checking whether the current element 
		while(stk.empty()==false and arr[stk.top()]<=arr[i]){
			stk.pop();
		}
		// This can be used for finding the index. the current index is i+1 is the index.
		// i-stk.top() is the value. 
		int span = stk.empty()?i+1:i-stk.top();
		cout<<span<<" ";
		stk.push(i);
	}
}

int main() 
{ 
    int arr[]={18,12,13,14,11,16};
    int n=6;
    printSpan(arr,n);
    cout<<endl;
    findSpan(arr,n);
    return 0; 
}