class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        // Create a 2D DP table, where dp[i][j] stores the minimum ASCII sum of deleted characters
        // for substrings s1[i:] and s2[j:]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: If one string is empty, delete all characters of the other string
        for (int i = n - 1; i >= 0; --i) {
            dp[i][m] = dp[i + 1][m] + s1[i];
        }
        for (int j = m - 1; j >= 0; --j) {
            dp[n][j] = dp[n][j + 1] + s2[j];
        }

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // No cost if characters are the same
                } else {
                    dp[i][j] = min(
                        s1[i] + dp[i + 1][j], // Delete s1[i]
                        s2[j] + dp[i][j + 1]  // Delete s2[j]
                    );
                }
            }
        }

        // The answer is stored in dp[0][0]
        return dp[0][0];
    }
};
/* class Solution {
public:
    int solve(string &s1, string &s2, int i, int j,vector<vector<int>>&dp) {
        int cost = 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (i == s1.size() || j == s2.size()) {
            // Return the sum of ASCII of remaining chars of remaining string
            for (int x = i; x < s1.size(); ++x) cost += s1[x];
            for (int x = j; x < s2.size(); ++x) cost += s2[x];
        } else if (s1[i] == s2[j]) {
            cost = solve(s1, s2, i + 1, j + 1,dp);
        } else {
            int cost1 = s1[i] + solve(s1, s2, i + 1, j,dp);
            int cost2 = s2[j] + solve(s1, s2, i, j + 1,dp);
            cost = min(cost1, cost2);
        }
        dp[i][j]=cost;
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1, s2, 0, 0,dp);
    }
};
*/