class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int startColor, int newColor) {
        // Check boundary conditions and if the pixel matches the start color
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != startColor) {
            return;
        }

        // Change the color of the current pixel
        image[x][y] = newColor;

        // Perform DFS on all adjacent pixels
        dfs(image, x + 1, y, startColor, newColor); // Down
        dfs(image, x - 1, y, startColor, newColor); // Up
        dfs(image, x, y + 1, startColor, newColor); // Right
        dfs(image, x, y - 1, startColor, newColor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];

       
        if (startColor == color) {
            return image;
        }

       
        dfs(image, sr, sc, startColor, color);

        return image;
    }
};