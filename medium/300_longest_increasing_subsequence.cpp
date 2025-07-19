class Solution {
public:
    int solveUsingDP(vector<int>& nums, int prevIndex, int curr, vector<vector<int>>& dp) {
        // Base case: If we have traversed the entire array
        if (curr == nums.size()) {
            return 0;
        }

        // Check if the result is already computed
        if (dp[prevIndex + 1][curr] != -1) {
            return dp[prevIndex + 1][curr];
        }

        // Option 1: Exclude the current element
        int exclude = solveUsingDP(nums, prevIndex, curr + 1, dp);

        // Option 2: Include the current element if it forms an increasing subsequence
        int include = 0;
        if (prevIndex == -1 || nums[curr] > nums[prevIndex]) {
            include = 1 + solveUsingDP(nums, curr, curr + 1, dp);
        }

        // Store the result in the DP table and return it
        return dp[prevIndex + 1][curr] = max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // Initialize a DP table with -1, with size (n+1) x n
        // prevIndex ranges from -1 to n-1, so we offset by 1
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solveUsingDP(nums, -1, 0, dp);
    }
};

/*
int solveUsingRecursion(vector<int>& nums, int prevIndex, int curr) {
        // Base case
        if (curr == nums.size()) {
            return 0;
        }

        //  Exclude the current element
        int exclude = solveUsingRecursion(nums, prevIndex, curr + 1);

        //: Include the current element if it forms an increasing subsequence
        int include = 0;
        if (prevIndex == -1 || nums[curr] > nums[prevIndex]) {
            include = 1 + solveUsingRecursion(nums, curr, curr + 1);
        }

        // Return the maximum of include and exclude
        return max(include, exclude);
    }
*/