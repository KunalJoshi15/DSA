#include<bits/stdc++.h>

using namespace std;

// Windows Sliding algorithm.
// Given an array of integers and a number k, find the max sum k consecutive elements.
// Each time a window of k elements is considered.

/*
The naive approach to solve this particular problem will be to consider k elements from the starting position. Then from the next position the next k elements are considered.

*/

int naive_sliding(int arr[],int n,int k){
    int max_sum = INT_MIN;
    for(int i=0;i+k-1<n;i++){
        int sum=0;
        for(int j=0;j<k;j++){
            sum = sum+arr[i];
        }
        max_sum=max(sum,max_sum);
    }
    return max_sum;
}
// The time complexity of this solution is O(n-K*K)

int linearSliding(int arr[],int n,int k){
    int sum=0;
    int max_sum=0;
    int p=0;
    for(int i=0;i<k;i++){
        // This finds the sum of first k terms.
        sum = sum+arr[i];
    }
    max_sum=max(sum,max_sum);
    for(int i=k;i<n;i++){
        sum = sum+arr[i]-arr[i-k];
        max_sum=max(sum,max_sum);
    }
    return max_sum;
    //This particular solution which we have implemented is a linear time solution to the problem.
}

int main()
{
    return 0;
}