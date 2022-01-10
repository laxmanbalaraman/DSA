class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        for(int weight = 0; weight <= W; weight++){
            for(int item = 1; item < N; item++){
                if(wt[item] <= weight){
                    dp[weight] = max(dp[weight - wt[item]] + val[item],  dp[weight]);
                }
            }
        }
        return dp[W];
    }
};