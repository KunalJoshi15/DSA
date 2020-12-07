#include<bits/stdc++.h>
using namespace std;

void nextGreater(int arr[],int n)
{
    stack<int> s;
    s.push(arr[0]);
    // Last element is pushed onto the stack;
    for(int i=0;i<=n-2;i++)
    {
        while(s.empty()==false && s.top()<=arr[i])
        {
            s.pop();
        }
        int nextGreater = (s.empty())?-1:(s.top());
        cout<<nextGreater<<" ";
        s.push(arr[i]);
    }
}