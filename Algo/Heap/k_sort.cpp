#include<bits/stdc++.h>

using namespace std;

void sortK(int arr[],int n,int k){
	priority_queue<int,vector<int>,greater<int>> pq;
	//here we create a min heap
	// here we are inserting the initial k elements into the min heap so that the min element is at the top.
	for(int i=0;i<k;i++){
		pq.push(arr[i])
	}
	// each time we will keep the min element at the top 

	int index=0;

	for(int i=k+1;i<n;i++){
		// here we will be checking the values for the other elements which are present.
		// here the value of the index is incremented and the values are then stored in the array itself as per our requirement.
		arr[index++]=pq.top();
		pq.pop();
		pq.push(arr[i]);
	}
	// we will be simply popping out the elements from the heap and put at the end of the array. 
	while(pq.empty()==false){
		arr[index++] = pq.top();
		pq.pop();
	}
}
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 
 
int main() 
{ 
	int k = 3; 
	int arr[] = { 2, 6, 3, 12, 56, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	sortK(arr, n, k); 

	cout << "Following is sorted array" << endl; 
	printArray(arr, n); 

	return 0; 
} 
