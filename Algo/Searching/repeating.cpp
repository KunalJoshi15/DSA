#include<bits/stdc++.h>

using namespace std;
// In the super naive solution to the particular problem we have two for loops that are used for checking whether the particular element is present in the particular range.

int naive_repeating(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j])
				return arr[i];
		}
	}
	// If no element is repeating then we simply return the value -1.
	return -1;
}
// O(n log n) solution will be leveraging the concept of sorting. All the repeating elements will come one after the other element.
int non_repeating(int *arr,int n){
	sort(arr,arr+n);

	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]) return arr[i];
	}
	return -1;
}

// There is one more solution which has O(n) time complexity and O(n) space complexity,
int bool_arra(int *arr,int n){
	//In this solution we will be creating a boolean array of element which will keep the track of the elements which we have seen.
	// If the array will contain a value which is already true then we can simply use it as per our need.
	bool visited[n] = {false};
	for(int i=0;i<n;i++){
		if(visited[arr[i]]==true){
			return arr[i];
		}
	}
	return -1;
}
/*
We can slightly change the approach to solve this particular problem. In this case we 
will be considering the elements starts from the 1. There will be the technique of tortoise and hare will be used.
slow and fast pointers are used-> At the second pass the fast is kept at the location where the slow and fast meet. while slow is taken to the start now they are moved at the same pace.*/
int findRepeating(int *arr,int n){
	int slow = arr[0]+1; fast = arr[0]+1;

	do{
		// arr[arr[fast]+1]+1
		slow =arr[slow]+1;
		fast = arr[arr[fast]+1]+1;
	}while(slow!=fast);
	// all these things will happed till the value of the slow pointer and the fast pointer is the same after that we will reset the value of the slow pointer.
	slow = arr[0]+1;
	while(slow!=fase){
		fast = arr[fast]+1;
		slow = arr[slow]+1;
	}
	return slow-1;
	// This is similar to the solution in which elements start with 1. We will always add 1 to the slow and the fast pointer.
}


int main()
{
	int arr[] = {0,2,1,3,2,2};
}