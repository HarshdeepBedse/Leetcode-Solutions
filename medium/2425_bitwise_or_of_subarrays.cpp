class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        
        // Compute XOR of all elements in nums1
        for (int num : nums1) {
            xor1 ^= num;
        }
        
        // Compute XOR of all elements in nums2
        for (int num : nums2) {
            xor2 ^= num;
        }
        
        int result = 0;
        
        // If nums2 has an odd length, XOR1 contributes to the result
        if (nums2.size() % 2 == 1) {
            result ^= xor1;
        }
        
        // If nums1 has an odd length, XOR2 contributes to the result
        if (nums1.size() % 2 == 1) {
            result ^= xor2;
        }
        
        return result;
    }
};