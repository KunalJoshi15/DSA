#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    s.push(10);
    s.push(30);
    s.push(44);
    // size() method is used to find the values in the stack.
    // Stack can be used to reverse the order of the items that are present in the stack itself currently.
    /*
        Balanced parenthesis can be done using the concept of the stack itself.
        push the opening backetsif there is even one mismatch then this fails.
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            s.push(str[i]);
        }
        else{
            if(s.empty()==true)
            {
                return false;
            }
            else if(matching(str[i],s.top())==false)
            {
                return false;
            }
            else{
                s.pop();
            }
        }
        if(str.empty()==true)
            return true;
    */
}