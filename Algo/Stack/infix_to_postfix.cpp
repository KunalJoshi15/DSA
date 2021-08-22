#include<bits/stdc++.h>

using namespace std;
// At the initial stage the innermost part of the expression is evaluated.
// in case of the infix to postfix expression conversion we will be using the concept of the stack and the associativity.
int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s){
	stack<char> st;
	string result;

	for(int i=0;i<s.size();i++){
		char c = s[i];

		if((c>='a' and c<='z')||(c>='A' and c<='Z')||(c>='0' and c<='9'))
		{
			result += c;
		}
		else if(c=='('){
			st.push('(');
		}
		else if(c==')'){
			// If the top of the stack is the closing bracket then we will find the open bracket which is currently present in the stack.
			while(st.top()!='('){
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() and prec(s[i])<=prec(st.top())){
				result += st.top(); 
				st.pop();
			}
			st.push(c);
		}
	}

	while(!st.empty()){
		result += st.top();
		st.pop();
	}
	cout<<result<<endl;
}

int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}