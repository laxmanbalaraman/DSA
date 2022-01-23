class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mins = prices[0];
        int ans = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] > mins){
                int maxs = prices[i];
                ans = max(maxs - mins, ans);
            }
            else{
                mins = prices[i];
            }
        }
        return ans;
    }
};