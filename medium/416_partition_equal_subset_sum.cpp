class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            sum += num;
        }

        // If the total sum is odd, partitioning into two equal subsets is not possible
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        // Only keep two rows: previous and current
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);

        // Base case: It's always possible to form sum 0 (empty subset)
        prev[0] = true;
        curr[0] = true;

        // Fill the DP table row by row
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    // Include the current element or exclude it
                    curr[j] = prev[j] || prev[j - nums[i - 1]];
                } else {
                    // Exclude the current element
                    curr[j] = prev[j];
                }
            }
            // After processing the current row, copy it to the previous row
            prev = curr;
        }

        // The answer is in the last processed row
        return prev[target];
    }
};
/* class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            sum += num;
        }

        // If the total sum is odd, partitioning into two equal subsets is not possible
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        // DP table: dp[i][j] means whether it's possible to form sum `j` using the first `i` elements
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: It's always possible to form sum 0 (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    // Include the current element or exclude it
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    // Exclude the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        
        return dp[n][target];
    }
};


/*







/*class Solution {
public:
    bool solveusingdp(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp) {
        // Base cases
        if (sum == target) {
            return true; // Found a subset with the required sum
        }
        if (index >= nums.size() || sum > target) {
            return false; // Reached the end or exceeded the target
        }

        // If already computed, return the stored result
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }

        // Include the current element
        bool include = solveusingdp(nums, index + 1, sum + nums[index], target, dp);

        // Exclude the current element
        bool exclude = solveusingdp(nums, index + 1, sum, target, dp);

        // Store the result in dp table
        dp[index][sum] = include || exclude;
        return dp[index][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // Calculate the total sum
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If the total sum is odd, we cannot partition into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        // Initialize a dp table with -1 (uncomputed)
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        // Start the dp function
        return solveusingdp(nums, 0, 0, target, dp);
    }
};


*/


/*class Solution {
public:
    bool solveusingrecursion(vector<int>& nums, int index, int sum, int target) {
        // Base cases
        if (sum == target) {
            return true; // Found a subset with the required sum
        }
        if (index >= nums.size() || sum > target) {
            return false; // Reached the end or exceeded target
        } 

        // Include the current element
        bool include = solveusingrecursion(nums, index + 1, sum + nums[index], target);

        // Exclude the current element
        bool exclude = solveusingrecursion(nums, index + 1, sum, target);

        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // If the total sum is odd, we cannot partition into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        // Start the recursive check
        return solveusingrecursion(nums, 0, 0, target);
    }
};
*/