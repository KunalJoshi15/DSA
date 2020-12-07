#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq = {10,20,30};
    dq.push_front(5);
    dq.push_back(50);

    for(auto x:dq){
        cout<<x;
    }
    /*
    Functions and the operations which are performed by the deque is as follows.
    insert(it,7) 7 will be inserted;
    insert(it,2,3)
    Two times 3 will be inserted.
    erase function here as well is used to remove a particular value.
    */
}