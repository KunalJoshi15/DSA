#include<bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr,int s,int e){
    // This particular merge procedure is used to combine both the arrays as per our requirement.
    int i = s;
    int m = (s+e)/2;
    int j=m+1;
    // When merging the elements we count the inversions which are formed by the values which we have.
    vector<int> temp;
    // This particular loop will run until one of the array has been exhausted.
    int cnt=0;
    while(i<=m and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            cnt += (m-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    // There two cases now either the left part has the elements or the right side has the elemeents.

    while(i<=m){
        temp.push_back(arr[i++]);
    }

    while(j<=e){
        temp.push_back(arr[j++]);
    }
    // Only one of them execute;
    int k=0;
    for(int idx=s;idx<=e;idx++){
        arr[idx] = temp[k];
        k++;
    }
    return cnt;
}
// In the particular base case we can return the value of 0;
/*
This particular technique uses the concept of the merge sort in order to count the number of inversions which are present inside the particular array.
*/
int inversion_count(vector<int> &arr,int s,int e){
    // Initially we will be writing the base case for the problem.
    if(s>=e){
        return 0;
    }
    int mid = (s+e)/2;
    int C1 = mergesort(arr,s,mid);
    int C2 = mergesort(arr,mid+1,e);
    int CI = merge(arr,s,e);
    return C1+C2+CI;
}



int main(){
    vector<int> arr{10,5,2,0,7,6,4};

    int s=0;
    int e = arr.size()-1;

    int inversion_count = inversion_count(arr,s,e);

    for(int x:arr){
        cout<<x<<",";
    }
}
    // In case of the insertion sort it totally depends on the number of inversions that are present in the particular array. O(n+m) Here m represents the inversions that are present in the particular array.
    // For finding the number of inversions in a particular case we can solve the problem by O(n^2) solution comparing all the pairs which are possible.
    // Here we will be using the divide and conquer approach to solve the particular problem as per our requirement.
    // Find the inversions which are present in one part of the array after the division. Cross  inversions-> one element in one part while other one in other part.


