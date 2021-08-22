#include<bits/stdc++.h>

using namespace std;

int postfixEval(string p){
	stack<int> s;
	for(char ch:p){
		if(ch=='+'){
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = a+b;
			s.push(c);
		}
		else if(ch=='-'){
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b-a;
			s.push(c);
		}
		else if(ch=='*'){
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b*a;
			s.push(c);
		}
		else if(ch=='/'){
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b/a;
			s.push(c);
		}
		else{
			int p = ch-'0';
			s.push(p);
		}
	}
	return s.top();
}

int main()
{
	string p = "12+3*";
	int evaluate = postfixEval(p);
	cout<<evaluate;
}