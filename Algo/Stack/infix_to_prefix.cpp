#include<bits/stdc++.h>

using namespace std;

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

void infixToPrefix(string s){
	reverse(s.begin(),s.end());
	string res="";
	stack<char> stk;
	for(int i=0;i<s.length();i++){
		char ch = s[i];

		if((ch>='a' and ch<='z')||(ch>='A' and ch<='Z')||(ch>='0' and ch<='9')){
			res += ch
			// IF the current term is a simple character then we can simply push it to the result string.
		}
		else if(ch==')'){
			// Here the closed bracket will be treated as the open bracket
			stk.push(ch);
		}
		else if(ch=='('){
			while(stk.top()!=')'){
				res += ch;
				stk.pop();
			}
			stk.pop();
		}
		else{
			while(!stk.empty() and prec(ch)<=prec(stk.top())){
				res += stk.top();
				stk.pop();
			}
			stk.push(ch);
		}
	}
	while(!stk.empty()){
		res += stk.top();
		stk.pop();
	}
	reverse(res.begin(),res.end());
	cout<<res;
}

int main()
{
	string p = "a+b*(c-d)";
	infixToPrefix(p);
}