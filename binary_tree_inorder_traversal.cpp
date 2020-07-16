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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> soln;
        treeTraverse(root, soln);
        
        return soln;
    }
    
    void treeTraverse(TreeNode *node, vector<int> &soln) {
        if (node == NULL) return;
        treeTraverse(node->left, soln);
        soln.push_back(node->val);
        treeTraverse(node->right, soln);
    }
};