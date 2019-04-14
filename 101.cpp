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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) 
            return true;
        reverseRightSubTree(root->right);
        return isSameTree(root->left, root->right);
    }
    
private:
    void reverseRightSubTree(TreeNode* node) {
        if (node==NULL)
            return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        reverseRightSubTree(node->left);
        reverseRightSubTree(node->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p&&!q) 
            return true;
        else if (!q&&p)
            return false;
        else if (!p&&q)
            return false;
        else {
            if (p->val != q->val)
                return false;
            else {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
        
    }
};
