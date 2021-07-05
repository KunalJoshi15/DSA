#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string input){
    stack<char> s;
    for(auto ch:input){
        switch(ch){
            case '(':
            case '[':
            case '{':
                s.push(ch);
                break;
            case ')':
                if(s.empty() and s.top()=='('){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            case ']':
                if(s.empty() and s.top()=='['){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            case '}':
                if(s.empty() and s.top()=='}'){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            default: continue;
        }
    }
}

int main()
{
    // When there is a opening bracket then we will be simply pushing that bracket onto the stack.
    // While popping the brackets from the stack we check the value which is in the top of the stack.
    
}