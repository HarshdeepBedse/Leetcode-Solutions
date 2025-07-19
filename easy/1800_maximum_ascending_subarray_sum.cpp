class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0]; // Start with the first element
        int maxSum = sum;  // Track the maximum sum

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];  // Add to the sum if current number is greater than previous
            } else {
                maxSum = max(maxSum, sum);  // Update max sum if needed
                sum = nums[i];  // Reset the sum to current element
            }
        }

        return max(maxSum, sum);  // Return the maximum sum after the loop
    }
};