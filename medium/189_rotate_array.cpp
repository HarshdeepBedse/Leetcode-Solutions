class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle case when k > n

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);   
        reverse(nums.begin() + k, nums.end());     // Reverse remaining elements
    }
};