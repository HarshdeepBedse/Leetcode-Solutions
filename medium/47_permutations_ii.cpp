#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index, set<vector<int>>& uniquePerms) {
        if (index >= nums.size()) {
            if (uniquePerms.find(nums) == uniquePerms.end()) {
                ans.push_back(nums);
                uniquePerms.insert(nums);
            }
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(nums, ans, index + 1, uniquePerms);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> uniquePerms;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        solve(nums, ans, 0, uniquePerms);
        return ans;
    }
};