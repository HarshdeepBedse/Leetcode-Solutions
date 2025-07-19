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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {}; // If n is 0, return an empty list as there are no trees
        return buildTrees(1, n); // Start the recursive tree generation from the range [1, n]
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> result;

        // Base case: If the range is invalid (start > end), return a list containing nullptr (empty tree)
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Loop through all values from 'start' to 'end' to consider each as the root
        for (int i = start; i <= end; i++) {
            // Recursively generate all left subtrees using values less than 'i'
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);

            // Recursively generate all right subtrees using values greater than 'i'
            vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

            // Combine each left subtree with each right subtree
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    // Create the root node with value 'i'
                    TreeNode* root = new TreeNode(i);
                    root->left = left; // Attach the left subtree
                    root->right = right; // Attach the right subtree
                    result.push_back(root); // Add the new tree to the result
                }
            }
        }
        return result; // Return all generated trees for the current range
    }
};