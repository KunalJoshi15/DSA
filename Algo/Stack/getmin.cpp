// If there are only positive numbers are being into the stack then the solution is very easy.
#include<bits/stdc++.h>

using namespace std;

int main()
{
	stack<int> s;
	// There will be a seperate variable created for these particular functionalities.
	// We will write the code logic for finding the peek element.
}

int getMin()
{
	return min;
}

int peek()
{
	t = s.peek();
	return (t<=0)?min:t;
}

int pop()
{
	t = s.pop();
	// during the popping of the elements if the current element is min then we can make the changes to the min as required.

	if(t<=0){
		res = min;
		// min will be changed.
		min = min-t;
		return res;
	}
	else{
		return t;
	}
}

int push(int x){
	if(s.empty()){
		min = t;
		s.push(x);
	}
	else if(x<=min){
		// If the current number is smaller than the min element then we will be changing the min part.
		// x-min value needs to be pushed as we need to restore the previous min element after the current min is popped.

		s.push(x-min);
		min=x;
	}
	else {
		// If the number is a positive number then we will simply push it onto the stack.
		s.push(x);
	}
}