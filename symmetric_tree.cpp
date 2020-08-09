// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if ( root == NULL || (root->left == NULL && root->right == NULL)) return true;
        if (root->left == NULL || root->right == NULL) return false;
        
        TreeNode* treeL = root->left;
        TreeNode* treeR = root->right;
        
        return checkSymmetry(treeL, treeR);
    }
    
    bool checkSymmetry(TreeNode* treeL, TreeNode* treeR) {
        if(treeL == NULL && treeR == NULL) return true;
        if((treeL != NULL && treeR == NULL) || (treeL == NULL && treeR != NULL) ) return false;
        if(treeL->val != treeR->val) return false;
        
        return checkSymmetry(treeL->left, treeR->right) && checkSymmetry(treeL->right, treeR->left);
    }
};