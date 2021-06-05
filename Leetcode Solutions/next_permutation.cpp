#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        // This will be finding the first value which is out of order which means that the i+1 element is smaller than the prev element.
        // Then simply find the position of the element.
        while(i>=0 && nums[i+1]<=nums[i]){
            i--;
        }
        if(i>=0){
            int j = nums.size()-1;
            // Find the position of the element which is larger than the element which is out of order. then simply swap the numbers and then 
            // reverse the array itself.
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums,i,j);
        }
        reverse(nums,i+1);
    }
    
    void reverse(vector<int> &nums,int start){
        int i=start,j=nums.size()-1;
        while(i<j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    
    void swap(vector<int> &nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
};