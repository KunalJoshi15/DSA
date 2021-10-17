#include<bits/stdc++.h>

using namespace std;

class MinHeap{
	int *arr;
	int size;
	int capacity;

public:
	MinHeap(int c){
		size = 0;
		capacity = c;
		arr = new int[c];
	}
	// this basically initialize a bare heap with the 11 elements.
	// Here we have defined the constructor in order to make the heap.
	int left(int i){return 2*i+1;}
	int right(int i){return 2*i+2;}
	int parent(int i){return (i-1)/2;}
	// this is the basic way in which the insertion of an element works in an array.
	void insert(int x){
		if(size==capacity) return;
		size++;
		arr[size-1]=x;

		for(int i=size-1;i!=0 and arr[parent(i)]>arr[i];){
			swap(arr[i],arr[parent(i)]);
			i = parent(i);
		}
	}

	void minHeapify(int i){
		int lc = left(i);
		int rc = right(i);
		int smallest = i;

		if(lc<size and arr[lc]<arr[i]){
			smallest = lc;
		}
		if(rc<size and arr[rc]<arr[i]){
			smallest = rc;
		}
		if(smallest!=i){
			swap(arr[smallest],arr[i]);
			minHeapify(smallest);
		}
	}

	int extractMin()
	{
		if(size==0) return INT_MAX;
		if(size==1){
			size--;
			return arr[0];
		}
		swap(arr[0],arr[size-1]);
		size--;
		minHeapify(0);
		return arr[size];
	}

	void decreaseKey(int i,int x){
		arr[i] = x;
		while(i!=0 and arr[parent(i)]>arr[i]){
			arr[parent[i]]=arr[i];
			i=parent(i);
		}
	}
	// firstly we will be setting the current value as the min then we will be simply extracting the minimum.
	void deleteKey(int i){
		decreaseKey(i,INT_MIN)
		extractMin();
	}
	// here  we are calling the minHeapify for the internal nodes which are there
	void buildHeap(){
		for(int i=(size-2)/2;i>=0;i--){
			minHeapify(i);
		}
	}
};

int main() 
{ 
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << " ";
    return 0;
} 

