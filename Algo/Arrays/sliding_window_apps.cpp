#include<bits/stdc++.h>

using namespace std;
/*
If there is an array of non negative elements provided to us and we need to find the 
sum of the array such that it forms a certain number.
We can simply use the naive approach it provides us the O(n^2) solution. The other approach that we can use is the sliding window approach.

In case of the optimized approach that takes the O(n) time complexity and O(1) space.
In case of the window sliding technique we maintain two variables one is for the starting and the other one is for the end part.
We will be initializing the current window sum as the first element then afterwards.

*/
// THere will be one question there are two loops in this code therefore the time complexity would be O(n^2) but the time complexity for the particular solution is O(n) as we are just pushing the n elements to the window and then we are simply removing those elements therefore 2n operations are performed at max.
int arraySum(int arr[],int n,int sum){
    int curr_sum = arr[0];
    int s=0;
    for(int i=0;i<n;i++){
        //clean the prev window. Before adding the current element we need to perform the cleaning which is required by us.
        while(curr_sum>sum && s<i-1){
            curr_sum -=arr[s];
            s++;
        }
        if(curr_sum==sum) return true;
        if(i<n) curr_sum += arr[i]; 
    }
    // If the current sum is equal to the sum then we simply return the value as per our need.
    return curr_sum == sum;
}
int main(){

}