#include<bits/stdc++.h>
#define ll long long
ll dp[505][505];

ll solve(vector<int>& ar,ll i,ll j)
{
	// here we have defined the i and j values which is required by us.
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    for(int k=i;k<j;k++)
    {
        ans = max(ans,solve(ar,i,k)+solve(ar,k+1,j)+ar[i-1]*ar[k]*ar[j]);
    }
    return dp[i][j] = ans;
}
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        memset(dp,-1,sizeof(dp));
        return solve(nums,1,nums.size()-1);
    }
};