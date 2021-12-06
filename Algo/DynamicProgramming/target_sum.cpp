#include<bits/stdc++.h>

using namespace std;
/*
In case of the target sum problem we try dividing the problem into two sets.
one represents the addition of the elements while other part represents the sum of the elements.\
the things that we have are
s1+s2=sum
s1-s2 = target
s1-(sum-s1) = target
2s1 = target+sum
*/
void targetCount(vector<int> &nums,int i,int s,int target,int &count){
	if(i==nums.size()){
		if(s==target){
			count++;
		}
		// this return is important.
		return;
	}
	targetCount(nums,i+1,s+nums[i],target,count);
	targetCount(nums,i+1,s-nums[i],target,count);
}
// top down dynamic programming code for this particular problem will be.
int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum < S || (sum - S) % 2) return 0;
    int target = (sum - S) / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int n : nums)
        for(int i = target; i >= n; --i)
            dp[i] += dp[i - n];
    return dp[target];
}

int main()
{
	vector<int> nums = {1,1,1,1,1};
	int count = 0;
	int target = 3;
	targetCount(nums,0,0,target,count);
	cout<<count;
}