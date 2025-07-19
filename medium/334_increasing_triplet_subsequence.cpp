class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX, middle = INT_MAX;

        for (int num : nums) {
            if (num <= smallest) {
                // Update the smallest value
                smallest = num;
            } else if (num <= middle) {
                // Update the middle value
                middle = num;
            } else {
                // If we find a number greater than `middle`, we have a triplet
                return true;
            }
        }

        return false; // No triplet found
    }
};