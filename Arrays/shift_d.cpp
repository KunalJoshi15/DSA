#include<bits/stdc++.h>

using namespace std;
//This particular code represents the naive approach of solving the problem in this particular case.
// We have created a function that will left rotate the elements of the array and this is done d times.
void rotate(int *arr,int n)
{
    int first = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1]=first;
}
// There is one more approach which can be used. In this particular approach we will create a temporary array which 
// will contain d elements.

void rotate1(int *arr,int n,int d){
    // This function is an O(n) solution but requires a little more extra space.
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }
    for(int i=0;i<d;i++){
        arr[n-d+i] = temp[i];
    }
}

//There is a one very efficient solution to this particular problem. The solution goes like this.
void reverse(int *arr,int a,int b){
    while(a<b){
        swap(arr[a],arr[b]);
        a++;
        b--;
        // The time complexity which is required for this reverse function is O(n/2)-> O(n)
    }
}

void rotate2(int *arr,int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main()
{
    int arr[] = {1,5,2,3,5,7};
    int n=sizeof(arr)/sizeof(int);
    int d=3;
    for(int i=0;i<d;i++){
        rotate(arr,n);
    }
}