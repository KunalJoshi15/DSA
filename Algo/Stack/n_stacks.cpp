#include<bits/stdc++.h>

using namespace std;
// For implementing a fixed sized solution we will be implementing k stacks.
// We need to have k tops in order to implement k stacks in an array.
// If we want to implement k stacks in a particular array then we will have to make few changes.
// The next array which is present holds the index of the dext free slot.

struct kStacks{
	int *arr,*top,*next;
	int k,freeTop,cap;

	kStacks(int k1,int n){
		k = k1, cap=n;
		arr = new int[cap];
		top = new int[k];
		next = new int[cap];

		for(int i=0;i<k;i++){
			top[i]=-1;
		}
		freeTop=0;
		for(int i=0;i<cap-1;i++){
			next[i]=i+1;
		}
		next[cap-1] = -1;
	}

	void push(int x,int stk){
		// freeTop has the current value of the top which is free.
		int i = freeTop;
		// Here the value of free top will change.
		freeTop = next[i];
		// Here after placing the element we will change the value of next[i]=top[stk].
		next[i] = top[stk];
		// Here the top will be changed to current value of i. and freeTop has already been changed.
		top[stk] = i;
		arr[i]=x;
	}
	int pop(int stk){
		// i is the top index of the current stack.
		int i = top[stk];
		// top of the stack needs to be changed to next[i]. it holds the previous value.
	
		top[stk] = next[i];
		next[i] = freeTop;
		freeTop = i;
		return arr[i];
	}
};
// Order of the operations is very important.


int main()
{
	// Here we want to implement k stacks. There are three things used in this particular case.
	// next array maintains the previous and the next free value freeTop has the top value which is free.
	// We maintain the top of all the arrays. Therefore there are k top arrays.


}