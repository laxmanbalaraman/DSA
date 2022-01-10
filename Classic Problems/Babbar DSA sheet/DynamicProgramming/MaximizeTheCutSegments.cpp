
/// recursive 
class Solution
{
    public:
    int dp[10005];
    int cut (int n, int x, int y, int z){
    if(dp[n] != -1) return dp[n];
    
    if(n == 0) return dp[n] = 0;
    int a = INT_MIN, b = INT_MIN, c = INT_MIN;
    if(n >= x) a = cut(n - x, x, y, z);
    if(n >= y) b = cut(n - y, x, y, z);
    if(n >= z) c = cut(n - z, x, y, z);
    //if(a == -1 && b == -1 && c == -1) return dp[n] = -1;
    return dp[n] = (1 + max(a, max(b, c)));
        
        
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp, -1, sizeof(dp));
        int ans = cut(n, x, y, z);
        //for(int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
        return (ans < 0 ? 0 : ans);
    }
};


// iterative 

class Solution
{
    public:
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            if(i >= x && dp[i - x] != -1) dp[i] = max(dp[i], dp[i - x] + 1);
            if(i >= y && dp[i - y] != -1) dp[i] = max(dp[i], dp[i - y] + 1); 
            if(i >= z && dp[i - z] != -1) dp[i] = max(dp[i], dp[i - z] + 1);

        }
        return (dp[n] < 0 ? 0 : dp[n]);
    }
};