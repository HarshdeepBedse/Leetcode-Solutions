class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL) {
            return NULL;
        }

        //case 1: p and q both comes in left subtree ofroot node
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p,q);
            return leftAns;
        }
        //case 2: p and q both comes in right subtree of root node
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        
         if(p->val < root->val && q->val > root->val) {
            return root;
         }
    
         if(q->val < root->val && p->val > root->val) {
             return root;
         }
        return root;
    }
};