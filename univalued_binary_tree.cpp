// https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTreeHelper(root, root->val);
    }
    
    bool isUnivalTreeHelper(TreeNode* root, int& orig_val) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return (root->val == orig_val) ? true : false;
        
        return (root->val != orig_val) ? false : ( isUnivalTreeHelper(root->left, orig_val) && isUnivalTreeHelper(root->right, orig_val) );
    }
};