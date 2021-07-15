#include<bits/stdcc++.h>

using namespace std;



int main()
{
	// For finding the running median we will be creating two heaps 
	// One will be for the left part while the other one will be for the right part.
	priority_queue<int> leftheap; // This is the max heap;
	priority_queue<int,vector<int>,greater<int>> rightheap; //min heap


	int d;
	cin>>d;
// Here the min element will be pushed to the left heap.
	leftheap.push(d);
	float med = d;
	cout<<d<<" ";

	while(d!=-1){
		//left or right or equal;
		// If both the heaps in particular has the equal number of elements then the median is defined by the median of both the top element.
		if(leftheap.size()>rightheap.size()){
			// There can be to cases. Element is larger than the top of the left heap then we can directly push to the right heap.
			if(d<med){
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else{
				rightheap.push(d);
			}
			med = (leftheap.top()+rightheap.top())/2;
		}
		else if(leftheap.size()==rightheap.size()){
			if(d<med){
				leftheap.push(d);
				med = leftheap.top();
			}
			else{
				rightheap.push(d);
				med = rightheap.top();
			}
		}
		else{
			if(d<med){
				leftheap.push(d);
			}else{
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			med = (leftheap.top()+rightheap.top())/2;
		}
		cout<<med<<" ";// This concept can be used for printing the elements.
	}
	return 0;
}