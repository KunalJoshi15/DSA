#include<bits/stdc++.h>
using namespace std;
void stock_span()
{
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++)
    [
        while(s.empty()==false && arr[s.top]<=arr[i])
        {
            s.pop();
        }
        int span = (s.empty())?(i+1):(i-s.top());
        cout<<span<<" ";
        s.push(i);
    ]
}
int main()
{
    /*
        The values before a particular value
        The algorithm works in this particular way.
        push The starting index 
        If some greater element appears then pop the top element. if the stack is empty then the element is larger than all 
        the element which have currently been seen Therefore if stack is empty then i+1 will be span otherwise it would be current Index-topIndex;
        Then push the element which is larger. Smaller elements are always pushed because the span can be depenedent in it.

        In case of the previous greater element problem the same concept can be used all over again.
        Next greter element problem can be solved in O(n) time using the stacj.
    */
}