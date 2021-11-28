class Solution {
public:
    // here we are dropping an egg from a certain height.
    int superEggDropUtil(int e,int f,vector<vector<int>> &dp){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int low = 0;
        int high = f;
        int mn = INT_MAX;
        
        while(low<=high){
            int mid = (low+high)/2;
            int a = superEggDropUtil(e-1,mid-1,dp);
            int b = superEggDropUtil(e,f-mid,dp);
            int c = 1+max(a,b);
            
            if(a>b){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
            mn = min(mn,c);
        }
        return dp[e][f] = mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return superEggDropUtil(k,n,dp);
    }
};