class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Create a 2D DP table for memoization
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Fill in the DP table using the base case
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];  // When there's only one element, it is the score
        }

        // Fill the DP table in bottom-up manner
        for (int len = 2; len <= n; ++len) {  // len is the length of the subarray
            for (int left = 0; left <= n - len; ++left) {
                int right = left + len - 1;
                dp[left][right] = max(nums[left] - dp[left + 1][right], nums[right] - dp[left][right - 1]);
            }
        }

        // If the score difference is >= 0, Player 1 can win or tie
        return dp[0][n - 1] >= 0;
    }
};


/* Reecursive solution
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1, true) >= 0;
    }
    
    int solve(vector<int>& nums, int left, int right, bool player1Turn) {
        if (left > right) return 0;  // Base case: no numbers left
        
        if (player1Turn) {
            // Maximize score for Player 1
            return max(nums[left] + solve(nums, left + 1, right, false),
                       nums[right] + solve(nums, left, right - 1, false));
        } else {
            // Minimize Player 1's score (Player 2 plays optimally)
            return min(-nums[left] + solve(nums, left + 1, right, true),
                       -nums[right] + solve(nums, left, right - 1, true));
        }
    }
};
*/