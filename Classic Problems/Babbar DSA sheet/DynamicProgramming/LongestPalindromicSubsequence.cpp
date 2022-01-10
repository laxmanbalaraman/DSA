int longestPalindromeSubsequence(string a)
{
    // Write your code here.
    int n = a.length();
    string b(n, ' ');
    for(int i = n - 1; i >= 0; i--){
        b[i] = a[n - i - 1];
    }
    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
                }
            }
        }
    }
    return dp[n][n];
}