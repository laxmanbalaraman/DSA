class Solution{
public:
    int nCr(int n, int r){
        // code here
        // using pascal's triangle
        if(n < r) return 0;
        r = min(r, n - r);
        int MOD = 1e9 + 7;
        int dp[r + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = min(i, r); j >= 1; j--){
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
        return dp[r];
    }
};