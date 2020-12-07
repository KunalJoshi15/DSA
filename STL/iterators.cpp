#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={1,2,3,4};
    // This will point to the starting value of the vector that has been initialized.
    vector<int>::iterator it = a.begin();
    it++;
    cout<<*it;
    /*
    There are different functions whicha are used along with the iterators.
    next(it) will be pointing to the next iterator;
    advance(it,3) will increment the value of the iterator with 3.
    */
    return;
}