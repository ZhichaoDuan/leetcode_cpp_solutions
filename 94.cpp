// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> v;
//         helper(root,v);
//         return v;
//     }
//
//     void helper(TreeNode* root, vector<int>& v) {
//         if(!root) return ;
//         helper(root->left,v);
//         v.push_back(root->val);
//         helper(root->right,v);
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> v;
//         stack<TreeNode *> stk;
//         TreeNode *curr = root;
//         while(curr!=NULL||!stk.empty()) {
//             while(curr!=NULL) {
//                 stk.push(curr);
//                 curr=curr->left;
//             }
//             curr=stk.top();stk.pop();
//             v.push_back(curr->val);
//             curr=curr->right;
//         }
//         return v;
//     }
// };

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> v;
    TreeNode* curr=root;
    TreeNode* pre;
    while(curr!=NULL) {
      if (curr->left==NULL) {
        v.push_back(curr->val);
        curr=curr->right;
      }
      else{
        pre=curr->left;
        while(pre->right!=NULL) {
          pre=pre->NULL;
        }
        pre->right=curr;
        TreeNode *temp=curr;
        curr=curr->left;
        temp->left=NULL;
      }
    }
    return v;
  }
};
