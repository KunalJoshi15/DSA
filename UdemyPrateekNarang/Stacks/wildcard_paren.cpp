#include<bits/stdc++.h>

using namespace std;

bool possibleParen(string s){
	int n = s.size();
	stack<int> paren;
	stack<int> stars;
	// Here we will be using two stacks in order to reach to our answer.
	// 
	for(int i=0;i<n;i++)
	{
		char ch = s[i];
		if(ch=='('){
			paren.push(i);
		}
		else{
			if(ch==')'){
				if(!paren.empty())
				{
					paren.pop();
				}else{
					if(!stars.empty()){
						stars.pop();
					}
					else{
						return false;
					}
				}
			}
			else{
				stars.push(i);
			}
		}
	}
	while(!paren.empty()){
		if(stars.empty()) return false;
		if(paren.top()<stars.top()){
			paren.pop();
			stars.pop();
		}
		else{
			return false;
		}
	}
	return true;

}

int main()
{
	string s;
	cin>>s;
	if(possibleParen(s)){
		cout<<"This in particular is possible";
	}else{
		cout<<"Not possible";
	}
}