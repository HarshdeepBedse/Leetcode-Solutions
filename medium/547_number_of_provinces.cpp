class Solution {
public:
    void dfs(int src, unordered_map<int, bool>& vis, int n, vector<vector<int>>& isConnected) {
        vis[src] = true; // Mark the current node as visited
        int col = n;
        int row = src;

        for (int nbrindex = 0; nbrindex < col; nbrindex++) {
            int nbr = nbrindex;
            if (isConnected[row][nbrindex] == 1) { // Check if there's a connection
                if (!vis[nbr]) { // If the neighbor is not visited, perform DFS
                    dfs(nbr, vis, n, isConnected);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, bool> vis; // To track visited cities
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If the city is not visited, start a new DFS
                count++; // Increment province count
                dfs(i, vis, n, isConnected);
            }
        }

        return count;
    }
};