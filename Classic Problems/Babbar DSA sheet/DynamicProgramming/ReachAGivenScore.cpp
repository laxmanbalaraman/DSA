long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0]=1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
    int coins[] = {3, 5, 10};
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= n; j++){
            if(coins[i - 1] <= j)
            dp[j] += dp[j - coins[i - 1]];  
        }
    }
    return dp[n];
}