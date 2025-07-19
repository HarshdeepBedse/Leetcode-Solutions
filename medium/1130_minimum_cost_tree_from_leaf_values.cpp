class Solution {
public:
    int solveUsingTabulation(vector<int>& arr) {
        int n = arr.size();
        
        // DP table to store the minimum cost of merging subarrays
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over all possible subarrays
        for (int len = 2; len <= n; ++len) {  // length of subarray from 2 to n
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;

                int minCost = INT_MAX;

                // Try all possible splits for the subarray arr[start...end]
                for (int mid = start; mid < end; ++mid) {
                    // Find the maximum values in the left and right parts of the subarray
                    int leftMax = *max_element(arr.begin() + start, arr.begin() + mid + 1);  // max in left part
                    int rightMax = *max_element(arr.begin() + mid + 1, arr.begin() + end + 1);  // max in right part
                    
                    // Cost for this split is the product of the maximum values of the two parts
                    int cost = leftMax * rightMax;

                    // Calculate the total cost: current split cost + the cost of merging the two subarrays
                    int totalCost = dp[start][mid] + dp[mid + 1][end] + cost;

                    // Update the minimum cost
                    minCost = min(minCost, totalCost);
                }

                dp[start][end] = minCost;
            }
        }

        return dp[0][n - 1];  // Return the minimum cost for the entire array
    }

    int mctFromLeafValues(vector<int>& arr) {
        return solveUsingTabulation(arr);
    }
};





/* usingg memoisation 
class Solution {
public:
    
    int calculateMinSum(vector<int>& arr, int start, int end, vector<vector<int>>& dp) {
        // Base case: when the subarray has only one element (a leaf node), return 0 as no non-leaf nodes exist
        if (start == end) {
            return 0;
        }

       
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int minSum = INT_MAX;

        // Try every possible position for splitting the array into two parts
        for (int mid = start; mid < end; mid++) {
            // Maximum values in the left and right parts of the array
            int leftMax = *max_element(arr.begin() + start, arr.begin() + mid + 1);  // max value in left part
            int rightMax = *max_element(arr.begin() + mid + 1, arr.begin() + end + 1);  // max value in right part

            // Cost for the non-leaf node is the product of the maximum values in the left and right subtrees
            int cost = leftMax * rightMax;

            // Recursively calculate the cost for the left and right subarrays
            int leftSum = calculateMinSum(arr, start, mid, dp);
            int rightSum = calculateMinSum(arr, mid + 1, end, dp);

            // Total cost for this split is the sum of the left and right subtree costs plus the cost of the current non-leaf node
            int totalCost = leftSum + rightSum + cost;

            // Update the minimum sum
            minSum = min(minSum, totalCost);
        }

        // Cache the result
        dp[start][end] = minSum;
        return minSum;
    }

    // Main function to calculate the minimum cost to remove the leaf values
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // Create a DP table and initialize with -1 (indicating not calculated)
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Call the helper function to get the result
        return calculateMinSum(arr, 0, n - 1, dp);
    }
};
*/