class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex; // Map to store number and its index

        for (int i = 0; i < nums.size(); ++i) {
            int sum = target - nums[i];

         
            if (numToIndex.find(sum) != numToIndex.end()) {
               
                return {numToIndex[sum], i};
            }

            // Otherwise, add the current number and its index to the map
            numToIndex[nums[i]] = i;
        }

        // If no solution is found (shouldn't happen as per the problem statement)
        return {};
    }
};