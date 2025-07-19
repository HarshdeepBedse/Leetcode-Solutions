class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Start from the second last row and move upwards
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                // Update the current element to be the sum of itself and the minimum of the two adjacent elements from the row below
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        
        // The top element now contains the minimum path sum
        return triangle[0][0];
    }
};