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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0)
            return NULL;
        return helper(inorder, postorder, postorder.size()-1, 0, postorder.size()-1);
    }
    
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int p, int in_st, int in_end) {
        if (in_st>in_end)
            return NULL;
        TreeNode *nn = new TreeNode(postorder[p]);
        int idx = in_st;
        while(idx<=in_end) {
            if (postorder[p]==inorder[idx])
                break;
            idx++;
        }
        
        nn->right = helper(inorder, postorder, p-1, idx+1, in_end);
        nn->left = helper(inorder, postorder, p - in_end + idx - 1, in_st,idx-1);
        
        return nn;
    }
};
