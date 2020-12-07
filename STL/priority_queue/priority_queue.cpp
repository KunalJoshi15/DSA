#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    int arr[] = {10,5,15};
    // The priority queue is generally used to implement the heap data structure in CPP.
    // The procedure to create a min heap is as follows
    // priority_queue<int,vector<int>,greater<int>> pq; vectors are used as underlying data structure.
    // We can heapify a particular vector as well
    // Creating a heap in this particular way is cheaper as we only implementing the BuildHeap which takes a time O(n)
    priority_queue<int> p(arr,arr+5);
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    // Top will provide us the maximum element in this case.
    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}