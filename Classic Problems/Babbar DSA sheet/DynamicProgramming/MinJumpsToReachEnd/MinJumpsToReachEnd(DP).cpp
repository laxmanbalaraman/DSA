class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int dp[n];
        dp[n - 1] = 0;
        int end = n - 1;
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] + i >= end) dp[i] = 1;
            else{
                if(arr[i] == 0) dp[i] = -1;
                else{
                    int low = i + 1;
                    int high = arr[i] + i;
                    int min_jumps = INT_MAX;
                    for(int j = low; j <= high; j++){
                        if(dp[j] == -1) continue;
                        min_jumps = min(dp[j], min_jumps);
                    }
                    if(min_jumps == INT_MAX){
                    dp[i] = -1;
                    }
                    else dp[i] = 1 + min_jumps;
                }
            }
        }
        for(int i = 0; i < n; i++) cout << dp[i] << " "; cout << endl;
        return dp[0];
    }
};