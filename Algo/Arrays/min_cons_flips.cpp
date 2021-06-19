#include<bits/stdc++.h>

using namespace std;
/*
The basic approach in case of the min coin flips is that the 
In case of the naive approach we simply count the group of 0's and the group of 1's
Whichever is larger according to it flips are made and we will simply find the indices where this is present.

The efficient solution to this particular problem is very elegant. If the start and the end of the array has the same element. Then we can simply say that the count of the
element with which the array starts is larger than the other group count.

The second group of elements will always contribute to the array.
*/
int min_coin_flips(int arr[],int n){
    for(int i=1;i<n;i++){
        //This if condition is used to check if the current element and the adjacent element are not equal we come to know that we have entered some other group.
        // if the current element and the 0th index element are not equal.
        if(arr[i]!=arr[i-1]){
            if(arr[i]!=arr[0])
                cout<<"From "<<i<<"to";
            else 
                cout<<(i-1)<<endl;
        }
    }
    if(arr[n-1]!=arr[0])
        cout<<(n-1)<<endl;
}

int main(){

}