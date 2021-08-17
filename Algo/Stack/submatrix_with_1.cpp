#include<bits/stdc++.h>

using namespace std;
// The naive approach will be. considering all the submatrix which are possible if the current value is 1.
int largestMatrixNaive(int arr[][],int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){ 
				for(int k=i;k<)
			}
		}
	}
}
int getMaxRectArea(int arr[],int n){
	// Initially we will be creating an empty stack as per our requirement.

	stack<int> s;

	int res = 0;
	// DOES THE ONE TRAVERSAL.
	for(int i=0;i<n;i++){
		// considering the current element as the smallest element.
		// THis loop is used to find the previous smaller element.
		// THe item in the stack which is below the current top is the previous smaller element only.
		while(s.empty()==false an arr[s.top()]>=arr[i]){
			int tp = s.pop();
			// current top of the item is 
			curr = arr[tp]*(s.empty()?i:(i-s.top()-1));
			res = max(res,curr);
		}
		// Current index which is present is always pushed.
		s.push(i);
	}
	// Result value can be computed only for the item that is being popped.
	while(s.empty()==false){
		// These are the element which does not have the next smaller element.
		int tp = s.pop();
		curr = arr[tp]*(s.empty()?i:(i-s.top()-1));
		res = max(res,curr);
	}
	// If for a particular element there is no smaller element present in the array. then the area will be sizeof the array and value present in current index.
}
// in case of the effiecient solution we will be finding 
int efficientSum(int arr[][],int m,int n){
	// In this problem we will leverage the idea of the histogram matrix as per our requirement.
	// Considering the lowest row as the height of the histogram.
	int res = largestHist(mat[0],c);
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				arr[i][j] += mat[i-1][j];
			}
		}
		res = max(res,largestHist(arr[i],c));
	}	
	// find the area using this particular formula.
	return res;
}

int main()
{

}