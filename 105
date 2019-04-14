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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0)
            return NULL;
        return helper(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_st, int in_st, int in_end) {
        if (in_st>in_end)
            return NULL;
        TreeNode* node = new TreeNode(preorder[pre_st]);
        int idx = in_st;
        while(idx<=in_end) {
            if(inorder[idx] == preorder[pre_st])
                break;
            idx++;
        }
        node->left = helper(preorder, inorder, pre_st+1, in_st, idx-1);
        node->right = helper(preorder, inorder, pre_st+idx-in_st+1, idx+1, in_end);
        return node;
    }
};
