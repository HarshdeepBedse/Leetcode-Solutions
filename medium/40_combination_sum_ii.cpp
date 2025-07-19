#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void findcombination(int index, int target, vector<int>& candidates, vector<int>& v, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            if (candidates[i] > target) {
                break; // No need to continue if the current candidate exceeds the target
            }
            v.push_back(candidates[i]);
            findcombination(i + 1, target - candidates[i], candidates, v, ans); // Move to the next index
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        findcombination(0, target, candidates, v, ans);
        return ans;
    }
};