#include<bits/stdc++.h>

using namespace std;

pair<int,int> search_index(int arr[4][4],int x){
    int i=0,j=3;

    while(i<4 and j>=0 ){
        if(arr[i][j]==x){
            return {i,j};
        }
        else if(arr[i][j]<x){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1,-1};
}

int main(){
    // We can search for a particular element in an array very fastly. O(nxm) will be the worst case time complexity for finding the element.
    // There is a better approach to solve this particular problem we start from the top right corner of the matrix and then will move to left in the first row until we have found an element smaller than the current element.
}