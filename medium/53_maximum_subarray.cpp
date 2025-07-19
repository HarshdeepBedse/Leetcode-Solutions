

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN; // Initialize to the smallest possible integer
        int currentsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentsum += nums[i];
            if (currentsum > maxsum) {
                maxsum = currentsum;
            }
            if (currentsum < 0) {
                currentsum = 0;
            }
        }
        return maxsum;
    }
};