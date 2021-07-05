#include<bits/stdc++.h>

using namespace std;

void maxSubArray(vector<int> a,int k){
    // Algorithm 
    int n = a.size()-1;
    deque<int> Q(k);
    int i=0;
    //1. Process only yhe first K elements 
    for(i=0;i<k;i++){
        // We will bes storing the indices of the arrays. 
        while(!Q.empty() and a[i]>a[Q.back()]){
            // Here what we are doing is that we are checking whether the deque is already empty or not if not empty and the current element encountered is larger than that in deque then we will pop element from the deque.
            Q.pop_back();
        }
        // If the current character that we have encountered is smaller than the previous element. Then simply pop from the deque.
        Q.push_back(i);
    }


    // 2. Remaining the elements of the array.
    for(;i<=n;i++){
        //Remove the element from the left contraction when an index lies outside the current window range.
        while(!Q.empty() and Q.front()<=i-k){
            Q.pop_front();
        }
        while(!Q.empty() and a[i]>a[Q.back()]){
            // Here what we are doing is that we are checking whether the deque is already empty or not if not empty and the current element encountered is larger than that in deque then we will pop element from the deque.
            Q.pop_back();
        }
        Q.push_back(i);
    }
}

int main()
{
    // This particular method is used to find the maximum element which is currently present in the array as per our requirement.
    // Here we will be using the deque data structure Which allows us the following operations which are the push from the front and pop from the front and push from the back and pop from the back as well.
}

// Here we need to consider whether a particular range of elements are useful or not. They can be useful or not useful.
/*
    Let us take an example of this particular array 1,2,3,1,4,5,2,3
    here when we have seen the first element then that particular element seems to be useful.
    When encountering the next element.

    The element from the deque is removed in two cases. 
    1) Element is outside the window then it is removed form the deque.
    2) We have found a greater element which is present.
*/