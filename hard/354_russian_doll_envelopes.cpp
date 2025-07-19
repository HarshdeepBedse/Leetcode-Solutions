class Solution {
public:
    // Custom comparator to sort by width (ascending), and by height (descending)
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];  // If widths are equal, sort by descending height
        }
        return a[0] < b[0];  // Sort by ascending width
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort the envelopes by the custom comparison rule
        sort(envelopes.begin(), envelopes.end(), compare);
        
        // Step 2: Apply the Longest Increasing Subsequence (LIS) idea on heights
        vector<int> lis;  // This will store the increasing subsequence of heights
        
        for (auto& envelope : envelopes) {
            int height = envelope[1];  // Get the height of the current envelope
            
            // Find the position where the current height should go in the lis array
            auto pos = lower_bound(lis.begin(), lis.end(), height);
            
            if (pos == lis.end()) {
                // If the current height is larger than all in the lis array, append it
                lis.push_back(height);
            } else {
                // If the current height is smaller or equal, replace the existing one
                *pos = height;
            }
        }

        // The length of the lis array gives the maximum number of envelopes
        return lis.size();
    }
};