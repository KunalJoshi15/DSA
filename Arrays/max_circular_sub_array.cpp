#include<bits/stdc++.h>

using namespace std;
/*
The naive approach is O(n^2),
We will be considering each and every element as the starting element.
*/
int maxCircularSum(int arr[],int n)
{
    int res = arr[0];
    for(int i=0;i<n;i++){
        int curr_max = arr[i];
        int curr_sum = arr[i];
        // for each element we will be finding the maximum sum of all the subarrays which are present for that element.
        // Find the max of all the sums then that will be our answer.
        for(int j=1;j<n;j++){
            int index = (i+j)%n;
            curr_sum += arr[index];
            curr_max = max(curr_max,curr_sum);
        }
        res = max(res,curr_max);
    }
    return res;
}
// There is one solution with the complexity as follows.
//for the normal subarray we can simply find the max sum subarray using the kadane's algorithm.
// max sum of circular subarray. It is broken into two parts.
// Max sum in case of the circular subarray can be determined by finding the minimum sum. max circular sum will be the min sum. 

int normalMaxSum(int arr[],int n){
    int res = arr[0], maxEnding = arr[0];

    for(int i=1;i<n;i++){
        // Considering here the next element and the current element.
        maxEnding = max(arr[i],maxEnding+arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}

int overallMaxSum(int arr[],int n){
    int max_normal =  normalMaxSum(arr,n); //This finds the Normal array max sum.
    if(max_normal<0) return max_normal;
    int arr_sum = 0;
    for(int i=0;i<n;i++){
        arr_sum += arr[i];
        arr[i] = (-1)*arr[i];
    }
    // normalSum on the negative elements is represented as follows. This will be finding the min sum. Then negation of it will be subtracted from the total sum.
    int max_circular=arr_sum+normalMaxSum(arr,n);
    return max(max_normal,max_circular);
}


int main(){

}