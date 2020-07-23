// https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 != NULL && t2 == NULL) return t1;
        if (t1 == NULL && t2 != NULL) return t2;
        
        return addTrees(t1, t2);
    }
    
    TreeNode* addTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL || t2 == NULL) return t1;
        
        t1->val += t2->val;
        addTrees(t1->left, t2->left);
        addTrees(t1->right, t2->right);
        
        if(t1->left == NULL && t2->left != NULL) {
            t1->left = t2->left;
        }
        if(t1->right == NULL && t2->right != NULL) {
            t1->right = t2->right;
        }
        return t1;
    }
};