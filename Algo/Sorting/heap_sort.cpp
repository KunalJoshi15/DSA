#include<bits/stdc++.h>

using namespace std;

// The heart of the heapsort is the maxheapify procedure. Here we will be starting with the creation of the maxheap.
// The concept of the heapsort is similar to that of the selection sort. The similar process is used in this particular case.
void maxHeapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }

    // Here the condition which is being  mentioned for the largest and the lowest range. Is to provide a range outside which our data must not go.
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
    // If the current node is the largest among all then there is no point in recursively calling for the smaller sub problem.
    // We call the max heapify for all the nodes.
    // This process is recursively until we reach the root node.
}

// In the usage of the heap sort we use the process which is similar to that of selection sort. The max element of the max heap which is present at the root. 
// Will be placed to its next position.

void buildHeap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);
    for(int i=n-1;i>=1;i--){
        // Here the maximum element is taken and is placed at the last location.
        // We will then be calling the heapify funciton in order to create the heap tree with the heapsize now reduced so that the last element is not considered.
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

int main()
{
    // If an array is to be sorted in the increasing order then we simply use the concept of the max heap otherwise we use the concept of the min heap.
    // In order to create the max heap from an array we call the build heap procedure whose overall time complexity is O(n)
    // We will call the maxheapify function for all the nodes which are non leaf nodes.
    int arr[] = {4,5,6,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    heapSort(arr,n);
    //HeapSort is basically used as the hybrid sorting algorithms.
}