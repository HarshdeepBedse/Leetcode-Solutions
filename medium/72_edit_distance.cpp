class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // Create a DP table with (m+1) rows and (n+1) columns
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Initialize the DP table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // If one of the strings is empty, we need to insert/delete the other string
                if (i == 0) {
                    dp[i][j] = j; // Insert all characters of word2
                } else if (j == 0) {
                    dp[i][j] = i; // Delete all characters of word1
                } else {
                    // If characters match, no operation is needed
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                    } else {
                        // If characters don't match, take the minimum of replace, delete, or insert
                        dp[i][j] = min({dp[i - 1][j - 1] + 1,  // Replace
                                         dp[i - 1][j] + 1,      // Delete
                                         dp[i][j - 1] + 1});    // Insert
                    }
                }
            }
        }
        
        // The result is in dp[m][n]
        return dp[m][n];
    }
};