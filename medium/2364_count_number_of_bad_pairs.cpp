#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total_pairs = (n * (n - 1)) / 2;  // Total pairs (i, j) where i < j
        long long good_pairs = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;  // Compute nums[i] - i
            good_pairs += freq[key];  // Count how many times this key appeared before
            freq[key]++;  // Update frequency map
        }

        return total_pairs - good_pairs;  // Bad pairs = total_pairs - good_pairs
    }
};

