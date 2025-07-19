class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
        // Create a DP table with two states: buy (1) and sell (0)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // Base case: On the last day, no profit can be made
        dp[n][0] = dp[n][1] = 0;

        // Fill the DP table from the last day to the first
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    // We can either buy the stock or skip
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    // We can either sell the stock or skip
                    dp[i][buy] = max(prices[i]-fee + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }

        // The maximum profit starting at day 0 with the ability to buy
        return dp[0][1];
    }
};
    