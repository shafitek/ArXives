// https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return tailHasPathSum(root, sum, 0);
    }
    
    bool tailHasPathSum(TreeNode* root, int& target, int currSum) {
        if (root->left == NULL && root->right == NULL)
            return (currSum+root->val == target) ? true : false;
        
        return ( (root->left != NULL && tailHasPathSum(root->left, target, currSum+root->val)) ||
                (root->right != NULL && tailHasPathSum(root->right, target, currSum+root->val)) ) ? true : false;
    }
};