class Solution {
public:
    // Helper function using memoization
    int solveUsingMem(int start, int end, vector<vector<int>>& dp) {
        
        if (start >= end) {
            return 0;
        }

        
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = INT_MAX;

        // Try guessing each number in the range [start, end]
        for (int i = start; i <= end; i++) {
            // Calculate cost of guessing `i`
            int cost = i + max(solveUsingMem(start, i - 1, dp), solveUsingMem(i + 1, end, dp));
            // Take the minimum of all possible costs
            ans = min(ans, cost);
        }

        // Memoize the result
        dp[start][end] = ans;

        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        // Define the DP table with size (n+1) x (n+1) initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // Call the helper function for the range [1, n]
        return solveUsingMem(1, n, dp);
    }
};