#include<bits/stdc++.h>

using namespace std;
// there are two recursive solutions.
int solve(int *arr,int i,int j,int sum){
	if(i+1==j){
		// there are only two elements present in the array.
		return max(arr[i],arr[j]);
	}
	// here we are considering both the cases.
	// here we will find the solution that the opponent has made the best choice for it and then we subtract it from the entire sum that we currently have.
	return max(sum-solve(arr,i+1,j,sum-arr[i]),sum-solve(arr,i,j-1,sum-arr[j]));
}

int optimalNaive(int *arr,int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	return solve(arr,0,n-1,sum);
}
// Recursive Solution 2:
int solveWithoutSum(int *arr,int i,int j){
	if(i+1==j) return max(arr[i],arr[j]); // only two elements
	// here we are considering the current user is taking two coins.
	// ith coin is taking then opponent will always try to min of all the options. So from two cases min value will be considered.
	return max(arr[i]+min(solveWithoutSum(arr,i+2,j),solveWithoutSum(arr,i+1,j-1)),arr[j]+min(solveWithoutSum(arr,i+1,j-1),solveWithoutSum(arr,i,j+2)));
}

int main()
{

}