#include<bits/stdc++.h>

using namespace std;

bool balanced(string o){
	stack<char> p;

	for(int i=0;i<o.size();i++){
		char ch = o[i];
		if(ch=='('||ch=='{'||ch=='['){
			p.push(ch);
		}
		else{
			if(p.empty()){
				return false;
			}
			if(ch==')'){
				if(p.top()!='('){
					return false;
				}
				p.pop();
			}
			else if(ch=='}'){
				if(p.top()!='{'){
					return false;
				}
				p.pop();
			}
			else{
				if(p.top()!='['){
					return false;
				}
				p.pop();
			}
		}
	}
	return p.empty();
}

int main()
{
	string o;
	cin>>o;
	
	if(balanced(o)){
		cout<<"Balanced";
	}
	else{
		cout<<"Not Balanced";
	}
	return 0;
}
