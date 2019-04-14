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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
private:
    TreeNode *helper(vector<int>& nums, int start, int end) {
        if (start>end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(nums, start, mid-1);
        node->right = helper(nums, mid+1, end);
        return node;
    }
};
