class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long dp[n+1] = {0};
        dp[0] = 0, dp[1] = k, dp[2] = k*k;
        int MOD = 1e9 + 7;
        for(long long i = 3; i <= n; i++){
            dp[i] = (((dp[i-1] + dp[i-2]) % MOD)*(k-1)) % MOD;
        }
        return dp[n];
    }
};