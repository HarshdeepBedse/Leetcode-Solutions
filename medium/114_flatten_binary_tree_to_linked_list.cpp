class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten the left and right subtrees recursively
        flatten(root->left);
        flatten(root->right);

        // Store the right subtree
        TreeNode* rightSubtree = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;

        // Find the rightmost node of the current right subtree
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }

        // Attach the stored right subtree
        current->right = rightSubtree;
    }
};