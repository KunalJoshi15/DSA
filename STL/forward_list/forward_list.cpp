#include<bits/stdc++.h>
using namespace std;

int main()
{
    forward_list<int> a;
    a.push_front(1);
    a.pop_front();
    //  list represent the doubly linked list it performs all the operations which are already provided by the 
    // help of the forward_list there are still some additional features that it can provide.
    a.remove(2);
    /*
    Can be used to solve the josephus problem
    push_back() is also possible in case of the list and the .merge(l2) will merge the second list with the first list itself.
        in case of the insert_after(iterator,{list or single element}) we can even pass an itertor from which particular location we want to assign the values.
    */
    a.assign({1,23,5,6,6});
    return 0;
}