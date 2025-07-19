class Solution {
public:
    int rob(vector<int>& nums) {
        


    
        if (nums.size() < 2)
            return nums[0];

      
        vector<int> skipLastHouse(nums.begin(), nums.end() - 1);
        vector<int> skipFirstHouse(nums.begin() + 1, nums.end());

        int lootSkippingLast = robHelper(skipLastHouse);
        int lootSkippingFirst = robHelper(skipFirstHouse);

        
        return max(lootSkippingLast, lootSkippingFirst);
    }

private:
    int robHelper(vector<int>& nums) {
        if (nums.size() < 2)
            return nums[0];

        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (size_t i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};

    