class Solution{
    public:
    int ans = 0;
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n + 1][m + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(S1[i - 1] == S2[j- 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        ans = max(ans, dp[i][j]);
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                
            }
        }
        int big  = INT_MIN; int I, J;
        for(int i = 0; i <=n; i++){
            for(int j = 0; j <= m; j++){
                cout << dp[i][j] << '\t';
                if(big < dp[i][j]){
                    big = dp[i][j];
                    I = i;
                    J = j;
                }
            }
            cout << endl;
        }
        string s = "";
        while(dp[I][J] != 0){
            s += S1[I-1];
            I--; J--;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
        return ans;
    }
};