#include<bits/stdc++.h>

using namespace std;
// In case of the histogram problem we need to find the area which is possible because of the histogram.
// We need to find the largest rectangular area.
// Each pillar can be considered as the smallest unit.

// NAIVE SOLUTION FOR THIS PARTICULAR PROBLEM WILL BE THIS.
int getMaxRect(int arr[],int n){
	// In case of the naive solution each rectangular area can be considered as the smallest bar possible.
	int res = 0;

	for(int i=0;i<n;i++){
		int curr = arr[i];
		// We will be including all the bars which have height >= to the current bar.
		for(int j=i-1;i>=0;i--){
			if(arr[j]>=arr[i]){
				curr += arr[i];
			}
			else{
				// WHen we get the smaller bar then we can simply ignore that particular bar.
				break;
			}
		}
		// This is regarding the right part. which is possible.
		for(int j=i+1;j<n;j++){
			if(arr[j]>=arr[i]){
				// adding the value of the smallest bar.
				curr += arr[i];
			}
			else{
				// Here the right side bar as well.
				break;
			}
		}
		res = max(res,curr);
	}
	return res;
}
// For using the better approach we can use stack as per our requirement.
// using the stock span problem we can find the preious smaller element and next smaller element.
// If the current element is greater then we are pushing into the stack.
int getMaxArea(int arr[],int n){
    int res=0;
    int ps[n],ns[n];
    
    stack <int> s;
    // here we need to index of the values which are present. not the exact values.
    s.push(0);
    // Indexes will be pushed.
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int pse=s.empty()?-1:s.top();
        ps[i]=pse;
        s.push(i);
    }
    
    while(s.empty()==false){
        s.pop();
    }
    
    s.push(n-1);
    for(int i=n-1;i>0;i--){
    	// SAme from the last type.
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int nse=s.empty()?n:s.top();
        ns[i]=nse;
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
    	// This is calculated 
        int curr=arr[i];
        // Considering the current rectangle is the smallest rectangle.
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;   
}
// The optimized solution for this particular problem is. 
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

int main()
{
	int arr[] = {6,2,5,4,1,5,6};
	int n = sizeof(arr)/sizeof(int);

	// cout<<getMaxRect(arr,n);
	cout<<endl;
	int p = findRect(arr,n);
}