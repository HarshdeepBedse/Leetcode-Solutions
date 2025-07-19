/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store column indices and corresponding node values
        map<int, vector<pair<int, int>>> nodes; 
        // Queue for BFS: stores (node, row, col)
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Start BFS with root at (0, 0)
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int row = pos.first, col = pos.second;
            nodes[col].push_back({row, node->val});

            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        // Result vector
        vector<vector<int>> result;

        // Extract nodes column by column
        for (auto& [col, vec] : nodes) {
            // Sort the nodes by row, and by value if rows are the same
            sort(vec.begin(), vec.end());
            vector<int> colVals;
            for (auto& [row, val] : vec) {
                colVals.push_back(val);
            }
            result.push_back(colVals);
        }

        return result;
    }
};