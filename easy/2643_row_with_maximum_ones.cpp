#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int onecount = 0;
        int rowno = 0;
        
        // Traverse each row in the matrix
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            // Count the number of 1s in the current row
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            
            // Update max count of 1s and corresponding row index
            if (count > onecount) {
                onecount = count;
                rowno = i;
            }
        }
        
        // Return the row index with maximum 1s and the count of 1s in that row
        return {rowno, onecount};
    }
};