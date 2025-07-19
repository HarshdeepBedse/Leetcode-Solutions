class Solution {
public:
    string postorder(TreeNode* node, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& result) {
        if (!node) return "#";  // Use "#" to represent null nodes
        
        string left = postorder(node->left, subtreeCount, result);    // Recursively get the left subtree
        string right = postorder(node->right, subtreeCount, result);  // Recursively get the right subtree
        
        string subtree = to_string(node->val) + "," + left + "," + right;  // Form a string for the current subtree
        
        if (subtreeCount[subtree] == 1) {  // If this subtree has been encountered once before, it's a duplicate
            result.push_back(node);  // Add the root of this subtree to the result
        }
        
        subtreeCount[subtree]++;  // Increment the count of the current subtree
        
        return subtree;  // Return the string representing the current subtree
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> subtreeCount;
        postorder(root, subtreeCount, result);
        return result;
    }
    

};