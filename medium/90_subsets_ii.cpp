
class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);  // Add current subset to result

        for (int i = start; i < nums.size(); i++) {
           
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            current.push_back(nums[i]);  // Include current element
            backtrack(nums, i + 1, current, result);  // Recurse for next elements
            current.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        backtrack(nums, 0, current, result);
        return result;
    }
};