/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, -1, -1);
    }
    
private:
    bool isValid(TreeNode* root, int min, int max) {
        if (root == NULL) 
            return true;
        if (min != -1 && root->val<=min)
            return false;
        if (max != -1 && root->val>=max)
            return false;
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
        
    }
};
