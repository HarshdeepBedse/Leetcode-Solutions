class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j] represents the number of ways to roll i dice to get sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Base case: 1 way to get sum 0 with 0 dice
        dp[0][0] = 1;
        
        // Fill the dp table
        for (int i = 1; i <= n; ++i) {  // for each number of dice
            for (int j = 1; j <= target; ++j) {  // for each possible sum
                for (int face = 1; face <= k; ++face) {  // for each face of the dice
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }
        
     
        return dp[n][target];
    }
};