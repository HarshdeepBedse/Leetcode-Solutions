class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;

        for (int i = 0; i < n; ++i) {
            int diff = abs(nums[i] - nums[(i + 1) % n]);  // circular check
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};