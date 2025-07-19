class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string reversed_s = s; // Create a copy of the original string
        reverse(reversed_s.begin(), reversed_s.end()); // Reverse the copied string
        
        int n = s.size(); // Get the size of the string

        // DP table to store results of subproblems
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Apply LCS logic to find the longest common subsequence between s and reversed_s
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == reversed_s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // If characters match, increment result
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Otherwise, take max of the previous row/column
                }
            }
        }

        return dp[n][n]; // The length of the longest palindromic subsequence
    }
};