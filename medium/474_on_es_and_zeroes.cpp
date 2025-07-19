class Solution {
public:
    void convertStrsToNumStrs(vector<string>& strs, vector<pair<int, int>>& numStrs) {
        for (auto str : strs) {
            int zeros = 0, ones = 0;
            for (auto ch : str) {
                if (ch == '0') ++zeros;
                else ++ones;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> numStrs; // number of 0's, number of 1's
        convertStrsToNumStrs(strs, numStrs);
        
        // Initialize a DP table with size (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Iterate over each string's zeros and ones
        for (auto& p : numStrs) {
            int zeros = p.first;
            int ones = p.second;
            
            // Update the DP table from bottom to top, right to left to prevent reuse of the same string
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        // The maximum number of strings we can form is stored in dp[m][n]
        return dp[m][n];
    }
};




/* recursive solution 
class Solution {
public:
    void convertStrsToNumStrs(vector<string>& strs, vector<pair<int, int>>& numStrs) {
        for (auto str : strs) {
            int zeros = 0, ones = 0;
            for (auto ch : str) {
                if (ch == '0') ++zeros;
                else ++ones;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int solve(vector<pair<int, int>>& numStrs, int i, int m, int n) {
        if (i == numStrs.size()) return 0;
        
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;

        // If including the current string is possible
        if (m - zeros >= 0 && n - ones >= 0) {
            include = 1 + solve(numStrs, i + 1, m - zeros, n - ones);
        }

        // Exclude the current string
        exclude = solve(numStrs, i + 1, m, n);

        // Return the maximum of include or exclude
        return max(include, exclude);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> numStrs; // number of 0's, number of 1's
        convertStrsToNumStrs(strs, numStrs);
        return solve(numStrs, 0, m, n);
    }
};
*/