class Solution{
	public:
	int minimumCost(int cost[], int n, int w) 
	{ 
        // Your code goes here
        //int dp[w+1];
        vector<int>dp(w + 1, INT_MAX);
        dp[0] = 0;
        for(int kg = 1; kg <= n; kg++){
            for(int weight = 1; weight <= w; weight++){
                if(weight >= kg and cost[kg - 1] != -1){
                    if(dp[weight - kg]  != INT_MAX)
                    dp[weight] = min(dp[weight - kg] + cost[kg - 1], dp[weight]);
                }
            }
        }
        if(dp[w] == INT_MAX) return -1;
        return dp[w];
	} 
};