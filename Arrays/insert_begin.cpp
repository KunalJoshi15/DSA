#include<bits/stdc++.h>

using namespace std;

int insert(int arr[],int size,int index,int element){
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    // This is the elements are placed at the location. 
    arr[index]=element;
}
// This code will be shifting all the elements that are after the index where the element is to be inserted. 
// After the shifting of the elements at the index the element to be inserted is placed.