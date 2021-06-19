#include<bits/stdc++.h>

using namespace std;

int firstMissingPositive(int *arr,int n){
    for (int i = 0; i < n; i++) {
       
        // Loop to check boundary
        // condition and for swapping
        while (arr[i] >= 1 && arr[i] <= n
               && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    // IF the time complexity that is being mentioned is not that large then we can use some other technique.
   
    // Checking any element which
    // is not equal to i+1
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
   
    // Nothing is present return last index
    return n + 1;
}

int main(){
    int arr[] = {1,3,2,5,6,3};
    int m = firstMissingPositive(arr,sizeof(arr)/sizeof(int));
}