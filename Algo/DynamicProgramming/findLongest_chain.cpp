class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),compare);
        vector<int> dp(pairs.size(),1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = 0;
        for(int x:dp) if(x>ans) ans=x;
        return ans;
    }
};