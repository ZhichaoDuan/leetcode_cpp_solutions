class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> >v;
    if (!root) return v;
    queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty()) {
      int count = Q.size();
      vector<int> t_v;
      while(count--) {
        TreeNode *node = Q.front();
        if (node->left) Q.push(node->left);
        if (node->right) Q.push(node->right);
        t_v.push_back(node->val);
        Q.pop();
      }
      v.push_back(t_v);
    }
  }
};
