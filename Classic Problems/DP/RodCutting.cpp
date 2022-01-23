class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n+1], length[n];
        dp[0] = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) length[i] = i + 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i >= length[j-1])
                dp[i] = max(dp[i], dp[i - length[j-1]] + price[j-1]);
            }
        }
        return dp[n];
        
    }
};