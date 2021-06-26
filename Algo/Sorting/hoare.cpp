#include<bits/stdc++.h>

using namespace std;

// In the typical implementation of the hoare partition we consider the first element of the array as the pivot element.

int partition(int arr[],int l,int h){
	// The hoares partition is not a stable method hence the quick sort is not a stable sort.
	int pivot = arr[l];
	int i=l-1,j=h-1;

	while(true){
		do{
			l++;
		}while(arr[l]<pivot);
		do{
			j--;
		}while(arr[i]>pivot);

		if(i>=j) return j;
		swap(arr[i],arr[j]);
	}
}
// Naive partition is stable.
// The quick sort is using the tail call recursion which can be easily converted to loops by most of the modern compiler.
// This algorithm as well is a divide and conquer algorithm We break the problem into smaller parts and then we simply solve those smaller parts.
int quickSort(int arr[],int l,int h){
	if(l<h){
		int p=partition(arr,l,h);
		quickSort(arr,l,p);
		quickSort(arr,p+1,h);
	}
}

// IN CASE of the hoares partition there is a small change.
/*
The time complexity of the algorithm goes as follows.
The quick sort takes recursive cases.
Random number then expected time complexity is n log n.
The best case of quick sort comes when the array is always divided into two parts.
*/