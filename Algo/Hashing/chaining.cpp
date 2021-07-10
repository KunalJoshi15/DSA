// C++ program to demonstrate implementation of our 
// own hash table with chaining for collision detection 
#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int> *table;
    // Here for this particular structure we have created a particular hastable. we have even initialized the constructor with the default values.

    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }
    void insert(int k)
    {
        int i = k % BUCKET;
        table[i].push_back(k);
        // This will be simply pushing the element which is present at the last of the array.
    }
    bool search(int k)
    {
        int i = k % BUCKET;
        // there is the list of elements. In chaining the linked list is created.
        for (auto x : table[i])
           if (x == k)
              return true;
        return false;      
    }
    void remove(int k)
    {
        int i = k % BUCKET;
        table[i].remove(k);
        // This remove is used to remove an element from a particular location.
        // Here in this remove function we can pass the value of the key which is to be removed from the array.
    }
};

/*
The problem of the collision can be even reduced using the concept of the open addresssing the idea here in this particular case will
be to perform the task withing the given array size only we are not allowed to use the extra space as per our requirement.
The load factor in case of the open addressing is always <=1;
Linear Probing is used in case of the collision. linearly we will find the vacant place.

The search in case of the linear probing works in this particular way. We compute the value from the hash function. Then we will simply go to that location.
If an empty slot occurs in between then we can say that the element is not present. If entire hashmap is full then we will wait till we again come back to the startin index.

The deletaion in case of the open addressing could have caused some issues. When deleting a particular slot we do not mark the slot as empty we mark it as deleted as it can otherwise impact our search.
Due to the clustering all the operations becomes costly. Clustering the reduced by quadratic and the double hasing.
Quadratic probing guarentees us an empty slot only if the load factor is <0.5 and n/m m is prime.
*/

	// Driver method to test Map class 
	int main() 
	{ 
	    MyHash mh(7);
	    mh.insert(10);
	    mh.insert(20);
	    mh.insert(15);
	    mh.insert(7);
	    cout << mh.search(10) << endl;
	    mh.remove(15);
	    cout << mh.search(15);
	} 

    /*
    Double hashing
    hash(key,l) = (h1(key)+ih2(key))%m
    If h2(key) is relatively prime to m then it always find a free slot if there is one.
    This double hashing technique finds the appropriate slot and can even avoid clustering.

    h1(key)=key%7
    h2(key)=6-(key%6)
    The second part should not be 0. As it migh cause problems.
    */
