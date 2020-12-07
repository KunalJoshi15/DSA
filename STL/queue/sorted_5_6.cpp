#include<bits/stdc++.h>
using namespace std;

void printFirstN(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");

    for(int count=0;count<n;count++)
    {
        string curr = q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr+"5");
        q.push(curr+"6");
    }
}

int main()
{
    /*
        We can use a beautiful concept of the queue.
        first take the two numbers and push them into the queue. append 5 and 6 to those numbers and at last perform the level order traversal for those numbers.
    */
}