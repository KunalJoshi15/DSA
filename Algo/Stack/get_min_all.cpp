#include<bits/stdc++.h>

using namespace std;

int main()
{
	stack<int> s;
}

int getMin()
{
	return min;
}

int peek(){
	t = s.peek();
	return (t<=min)?min:t;
}

int pop()
{
	t = s.pop();
	if(t<=min){
		res = min;
		min = 2*min-t;
		return res;
	}
	else{
		// If the current element is greater than the min element then we can simply return the value.
		return t;
	}
}

int push(int x){
	if(s.empty()){
		min = t;
		s.push(x);
	}
	else if(x<=min){ 
		// Here if the element which is being pushed is smaller then the min then the element which will be pushed is. 2*x-min
		// min element will also be changed.
		s.push(2*x-min);
		min = x;
	}
	else {
		s.push(x);
	}
}