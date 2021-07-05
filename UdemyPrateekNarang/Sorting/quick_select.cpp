#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> arr,int s,int e){
	int pivot = arr[e];
	int i=s-1;
	for(int j=s;j<e;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}

// The quick select algorithm is used to find the exact index of a particular element.
// The concept which the quick select algo uses it initially it leverages the concept of the quick sort partition function.
// We will be finding the partition value index and then using it as a reference will traverse the array. If the element in the partition index is larger 
//Either we will be going to the left or right based on the condition.
// k is the position kth smallest element.
int quickselect(vector<int> arr,int s,int e,int k)
{
	int p = partition(arr,s,e);
	if(p==k) return arr[p];
	else if(k<p){
		return quickselect(arr,s,p-1,k);
	}
	else{
		return quickselect(arr,p+1,e,k);
	}
}

int main(){
	vector<int> arr{10,5,2,0,7,6,4};
	cout<<arr.size()<<endl;
	int n = arr.size();
	int k=3;
	int index = quickselect(arr,0,n-1,k);
	cout<<index;
}