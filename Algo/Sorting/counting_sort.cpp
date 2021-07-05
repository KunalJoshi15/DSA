#include<bits/stdc++.h>

using namespace std;
// There is more general purpose sorting algorithm which we can use in order to sort the elements.
void countSort(int arr[],int n,int k){
    int count[k];

    // Here we create an array which has the count
    for(int i=0;i<k;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<k;i++){
        count[i] = count[i]+count[i-1];
    }
    int output[n];
    // Here we can traverse the element from starting to the end as well but this way the sorting algorithm can be made stable.
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
    //This particular variation of the counting sort can be used by most of the algorithms.
}


int main()
{
    int arr[] = {1,4,4,1,0,1};
    int k=5;
    // k represent the max element which is present. We initially store the count of all the elements which are present in our array.
    int count[k]={0};
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        count[arr[i]]++;
    }
    for(int i=1;i<k;i++){
        count[i]=count[i]+count[i-1];
    }
    int index = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<count[i];j++){
            arr[index]=i;
            index++;
        }
    }
    // This is the naive way to implement the counting sort.
    // Here we consider all the elements which are present in the count array. one by one we will be placing those elements into their correct position.
    //Here in case of the counting sort we create an aux array for sorting all the elements which are present.

}