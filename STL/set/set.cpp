#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(70);
// set<int,greater<int>> s; is used to reverse the order now non increasing order.
// Set basically stores the items in a sorted order.
    for(int x:s)
    {
        cout<<x<<" ";
    }
// we can use the iterator as well as per our requirement. 
// For printing the items in the reverse order we can use the rbegin and rend iterators.
// Find function is used to check whether a particular item is present in the set or not.
//s.find(10) gives iterator to the element if present. clear() removes all the elements from the set. count and find can be used. erase remove the element from the set. it takes iterator.
    return 0;
// lower bound if the element is not present then it returns the iterator to the next element which is greater than the element if the element we have provided is the greatest then returns the end() iterator.
// Set is basically implemented in the top of Red Black trees.
}