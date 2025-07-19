class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp; // dp[sum] = count of ways to achieve this sum
    dp[0] = 1;

    // Process each number in the input array
    for (int num : nums) {
        // Temporary map to store new dp states for the current iteration
        unordered_map<int, int> nextDp;

        // Iterate through all sums in the current dp map
        for (auto it = dp.begin(); it != dp.end(); ++it) {
            int sum = it->first;   // Current sum
            int count = it->second; // Ways to achieve this sum

            // Add current number to the sum
            nextDp[sum + num] += count;

            // Subtract current number from the sum
            nextDp[sum - num] += count;
        }

        // Update dp with the new states
        dp = nextDp;
    }

    // Return the number of ways to achieve the target sum
    return dp[target];
    }
};