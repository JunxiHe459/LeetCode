class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1 > 6 ? n + 1 : 7 , 0);
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        for(int i = 7; i <= n; i++)
        {
            dp[i] = dp[i - 3] * 3;
        }
        
        return dp[n];
    }
};