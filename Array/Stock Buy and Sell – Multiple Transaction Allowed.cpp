// Problem Link: https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        
        for(int idx = n-1; idx >= 0 ; idx--){
            for(int flag = 1; flag>=0; flag--){
                if(flag == 0){
                    int buy = -prices[idx] + dp[idx+1][1];
                    int not_buy = dp[idx+1][0];
                    dp[idx][flag] = max(buy, not_buy);
                }
                else{
                    int sell = prices[idx] + dp[idx+1][0];
                    int not_sell = dp[idx+1][1];
                    dp[idx][flag] = max(sell, not_sell);
                }
            }
        }
        
        return dp[0][0];
    }
};
