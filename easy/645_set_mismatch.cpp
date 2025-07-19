

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);  // To store {duplicate, missing}
        unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Find duplicate and missing number
        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 2) ans[0] = i;  // Duplicate number
            if (freq[i] == 0) ans[1] = i;  // Missing number
        }

        return ans;
    }
};