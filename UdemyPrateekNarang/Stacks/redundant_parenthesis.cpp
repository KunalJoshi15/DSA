#include<bits/stdc++.h>
using namespace std;

bool redundant(string str){
    stack<char> s;
    for(char x:str){
        bool op=false;
        s.push(x);
        if(x==')')
        {
            while(s.empty() and s.top()!='('){
                if(s.top()=='+'||s.top()=='-'||s.top()=='/'||s.top()=='*'){
                    op=true;
                }
                s.pop();
            }
            s.pop();
            if(op==false){
                return true;
            }
        }
    }
    return false;
}
// If the true value is returned by the above function there there exists a redundant parenthesis in this particular case.

int main()
{
    // A particular parenthesis is redundant if there is no operator and operand inside it. 
    // We will even push the operator and operand.
    // Here while popping the elements from the stack we should be maintaining a boolean variable whether we encounter some operator or not.
}