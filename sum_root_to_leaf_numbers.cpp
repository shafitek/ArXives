// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    vector<int> soln_vec;
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        
        int soln = 0;
        getTreeLeafSum(root, 0);
        
        for(auto const & s : soln_vec) soln += s;
        
        return soln;
    }
    
    void getTreeLeafSum(TreeNode* tree, int sum) {
        if (tree == NULL) return;
        if (tree->left == NULL && tree->right == NULL) {
            soln_vec.push_back(sum*10+tree->val);
            return;
        }
        
        getTreeLeafSum(tree->left, sum*10+tree->val);
        getTreeLeafSum(tree->right, sum*10+tree->val);
    }
};