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
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    
private:
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == NULL) return true;

        if ((minNode != NULL && root->val <= minNode->val) || 
            (maxNode != NULL && root->val >= maxNode->val)) 
            return false;

        return helper(root->left, minNode, root) && 
               helper(root->right, root, maxNode);
    }
};