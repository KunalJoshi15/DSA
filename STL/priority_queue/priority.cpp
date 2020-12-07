#include<bits/stdc++.h>
using namespace std;

struct Person
{
    int age;
    float ht;
    Person(int a,float h)
    {
        age = a;
        ht=h;
    }
};

struct myCmp
{
    bool operator() (Person const &p1,Person const &p2)
    {
        return p1.ht<p2.ht;
    }
};

int main(){
    priority_queue<Person,vector<Person>,myCmp> pq;
    // This way we can create our own priority queue.
}

/*
The concept of the priority queue is widelt used 
) Dijkstra Algorithm 
2) Prims Algorithm
3) Huffman Algorithm
4) Heap Sort
And any other place where heap is used.

The heap data structure can be used for printing the k largest elements. Firstly create a max_heap and then do other things.
Using the min_heap data structure for the k largest elements works better than the max heap data structure.
when the value of k is very large then we should use the min heap solution as it provides the time complexity as O(n)

Purchasing maximum items can be done in two ways one is to use the concept of sorting which will give us the O(n log n) solution while the other one is 
O(n) by min heap.
For finding the frequency of the items we should use the unordered map.
Then we will take the unordered map and will either create a priority queue or a vector and will add 
item and its frequency to it.
We will be sorting the vector according to the second item and if two have same frequency then on the basis of first item. (Or create the priority queue using this concept both works fine.)
*/