#include<bits/stdc++.h>

using namespace std;
// In case of the naive approach we will be finding the places where the element can be present.
// Here we simply need to choose the k-1 cuts from the n-1 cuts which currently exists.

int sum(int *arr,int b,int e){
	int s = 0;

	for(int i=b;i<=e;i++){
		s += arr[i];
	}
	return s;
}
// Here k represents the number of students and n is the number of books.
int minPages(int *arr,int k,int n){
	if(k==1) return sum(arr,0,n-1);
	if(n==1) return arr[0];
	int res = INT_MAX;
	for(int i=1;i<n;i++){
		// This loop is for that cut can be applied to any place as per our requirement.
		res = min(res,max(minPages(arr,i,k-1),sum(arr,i,n-1)));
	}
	// Here in this particular solution we are giving the i to k-1 student and the remaining to the single student.
	//Whichever value is max will be considered.
	return res;
}

bool feasibleSolution(int *arr,int n,int k,int mid){
	int req = 1,sum=0;
	// Required number of people to finish the book will be initially equal to 1.

	for(int i=0;i<n;i++){
		if(sum+arr[i]>mid){
			// If the particular sum and the array element becomes > mid then one more person will be needed.
			req++;
			// Here we will reset the value of the sum we will be having a new sum here the next changes will be made.
			sum = arr[i];
		}
		else{
			sum += arr[i];
		}
	}
	return (req<=k);
}

int efficientMinPages(int *arr,int k,int n){
	// In the effiecient approach to this particular problem we will be finding the range which could be possible. 
	// The range will always be around the max book size and the sum of all the pages. We can perform the binary search within this particular range.
	int sum = 0;
	int maximum=INT_MIN;
	int res=0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		maximum = max(maximum,arr[i]);
	}
	int low = maximum;
	int high = sum;
	while(low<=high){
		int mid = (low+high/2);
		// If we have found the feasible solution then we will go to the left half in order to find even better solution to the problem.

		if(feasibleSolution(arr,n,k,mid)){
			res = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return res;
}

int main(){
	int arr[] = {10,20,30,40};
	int k = 3;
	int min = minPages(arr,k,sizeof(arr)/sizeof(int));	
}