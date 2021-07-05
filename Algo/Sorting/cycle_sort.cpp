#include<bits/stdc++.h>

using namespace std;
/*
In case of the cycle sort the time complexity is O(n^2)
This sorting algorithm is used because it has the least number of the memory writes.
As for each and every element it find the  elements smaller than it and then places  the element to its correct position.
THe cycle sort algorithm is in place but not stable algorithm.

The min swaps can be used to find the min swaps.
The current element is placed to its correct position. Then we will take the element with which it is replaced we try to find the correct position of that particular element.
*/

void cycleSortDistinct(int arr[],int n){
    // In case of the cycle sort we see the current element as the cycle starting point;
    // This is how in particular the cycle sort works. We pick the first element and finds the elements that are smaller than this particular element and then we basically place the element to its correct position.

    for(int cs=0;cs<n-1;cs++){
        int item = arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++){
            if(arr[i]<item){
                // Number of elements which are smaller than the current element are found.
                pos++;
            }
        }
        swap(item,arr[pos]);  
        // Here we will be checking whether the cycle is being formed or not. when the cycle is formed we again repeat the procedure for the other distinct element which is present.
        while(pos!=cs){
            pos = cs;
            for(int i=cs+1;i<n;i++){
                if(arr[i]<item){
                    pos++;
                }
                swap(item,arr[pos]);
            }
            //Here all the other elements are chosen and placed to their correct position.
        }
    }
}

int main()
{
    return 0;
}