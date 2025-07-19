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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // To store the final zigzag order traversal
        if (!root) return result;  // If the root is null, return an empty vector

        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);
        bool leftToRight = true; // Direction flag

        while (!q.empty()) {
            int size = q.size(); // Number of nodes in the current level
            vector<int> level(size); // To store nodes of the current level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Place node's value based on direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                // Add child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level); // Add the current level to the result
            leftToRight = !leftToRight; // Toggle the direction
        }

        return result;
    }
};