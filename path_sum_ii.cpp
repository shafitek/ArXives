// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> soln;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return {};
        tailHasPathSum(root, sum, 0, {});
        
        return soln;
    }
    // using tail recursion
    void tailHasPathSum(TreeNode* root, int& target, int currSum, vector<int> currVec) {
        if (root->left == NULL && root->right == NULL) {
             if (currSum+root->val == target) {
                 currVec.push_back(root->val);
                 soln.push_back(currVec);
             }
            return;
            
        }
        currVec.push_back(root->val);
        if(root->left != NULL) tailHasPathSum(root->left, target, currSum+root->val, currVec);
        if(root->right != NULL) tailHasPathSum(root->right, target, currSum+root->val, currVec);
    }
};