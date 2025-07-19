class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Boundary checks and water cell check
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
            return;
        }
        
        // Mark the current cell as visited by changing it to '0'
        grid[i][j] = '0';
        
        // Explore all 4 directions
        dfs(i - 1, j, grid); // Up
        dfs(i + 1, j, grid); // Down
        dfs(i, j - 1, grid); // Left
        dfs(i, j + 1, grid); // Right
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid); // Start DFS to mark all connected land
                }
            }
        }
        
        return count;
    }
};