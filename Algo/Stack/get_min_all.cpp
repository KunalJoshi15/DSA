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
		s.push(2*x-min);
		min = x;
	}
	else {
		s.push(x);
	}
}