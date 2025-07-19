
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Declare a 2D vector to store the Pascal's Triangle
        vector<vector<int>> dp(numRows);
        
        // Loop through each row
        for (int i = 0; i < numRows; ++i) {
            dp[i].resize(i + 1, 1); // Initialize the row with size (i+1) and all values as 1
            
            // Compute values for the inner elements (skip the first and last element)
            for (int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        
        return dp; // Return the completed Pascal's Triangle
    }
};