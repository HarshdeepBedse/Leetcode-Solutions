class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // Create a DP table with dimensions (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If characters match, add 1 to the result of the previous characters
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If characters do not match, take the maximum result from the left or top
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The bottom-right corner contains the result for the full strings
        return dp[m][n];
    }
};

    

/* 
int longestCommonSubsequence(string text1, string text2) {
        return LCSRecursive(text1, text2, 0, 0);
    }
private:
    int LCSRecursive(const string &text1, const string &text2, int i, int j) {
        // Base case: If either string is exhausted
        if (i == text1.length() || j == text2.length()) {
            return 0;
        }

        // If characters match
        if (text1[i] == text2[j]) {
            return 1 + LCSRecursive(text1, text2, i + 1, j + 1);
        } else {
            // If characters do not match, consider both possibilities: skip a character from text1 or text2
            return max(LCSRecursive(text1, text2, i + 1, j), LCSRecursive(text1, text2, i, j + 1));
        }
    }
};
*/