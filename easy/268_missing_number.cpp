class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

       
        int xorAll = 0;
        for (int i = 0; i <= n; i++) xorAll ^= i;

     
        int xorArray = 0;
        for (int num : nums) xorArray ^= num;

       
        return xorAll ^ xorArray;
    }
};