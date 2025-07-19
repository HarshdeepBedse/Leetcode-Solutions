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
void inorder(TreeNode* root,vector<int>&in){
    if(!root) return;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
TreeNode* build(vector<int>&in,int start,int end){
    if(start>end) return NULL;
    int mid=(start+end)/2;
    TreeNode* root=new TreeNode(in[mid]);
    root->left=build(in,start,mid-1);
    root->right=build(in,mid+1,end);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        return build(in,0,in.size()-1);
    }
};