#include<bits/stdc++.h>

using namespace std;

struct Interval{
    int st;
    int et;
};

bool compare(Interval i1,Interval i2){
    return i1.st>i2.st;
}

int main(){
    int arr[] = {1,2,2,3,3,2,1,1,2,3,4};

    sort(arr,arr+11,greater<int>());
// This third function is passed to perform the sorting in the descending order itself
    // If we want to sort a particular part of an array then we can provide that particular part only.
    Interval ar[] = {{6,3},{2,1},{4,3}};
    sort(ar,ar+3,compare);
    cout<<binary_search(arr,arr+6,8);
    // This particular function is required for performing the binary search to a particular function.
    cout<<lower_bound(arr,arr+6,2);
    // This particular lower bound function returns the pointer to the element if it is present in the array. if not present then will return the pointer to the value which is larger than the value being searched.
    cout<<upper_bound(arr,arr+6,2);
    // The difference between the lower bound function and the upper bound funciton is that it returns the index of the value which is just larget than the current one.
    cout<<__gcd(6,2);
    // The time complexity of the Tower of Hanoi is very large.
    return 0;
}