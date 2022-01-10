// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[M + 1][V + 1];
	    for(int i = 0; i <= M; i++) dp[i][0] = 0;
	    for(int i = 0; i <= V; i++) dp[0][i] = INT_MAX;
	    
	    for(int i = 1; i <= M; i++){
	        for(int j = 1; j <= V; j++){
	            if( j >= coins[i - 1]){
	                if(dp[i][j - coins[i - 1]] != INT_MAX){
	                    dp[i][j] = min (dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
	                }
	                else{
	                    dp[i][j] = dp[i-1][j];
	                }
	            }
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    return dp[M][V] != INT_MAX ? dp[M][V] : -1;
	    
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends