class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0 || s[0]=='0') return 0;
        
        if(s.length()==1) return 1;
        int count1=1,count2=1;        
        for(int i=1;i<s.length();i++){
            int d = s[i]-'0';
            int dd = (s[i-1]-'0')*10+d;
            int count=0;
            // here we are considering only the single digit character.
            if(d>0) count=count+count2;
            if(dd>=10 and dd<=26) count = count+count1;
            count1 = count2;
            count2 = count;
        }
        return count2;
    }

    int numDecodings(string s) {
        // here we have createed the dp array as per our requirement.
        vector<int> dp(s.length()+1);
        dp[0]=1;
        dp[1]=s[0]=='0' ? 0:1;
        for(int i=2;i<dp.size();i++){ 
            int onedigit=s[i-1]-'0';
            int twodigit=10*(s[i-2]-'0')+s[i-1]-'0';
            if(onedigit>=1) dp[i]+=dp[i-1];
            if(twodigit>=10 && twodigit<=26) dp[i]+=dp[i-2]; //>=10 will take care of the leading zero case
        }
        return dp[dp.size()-1];
    }
};