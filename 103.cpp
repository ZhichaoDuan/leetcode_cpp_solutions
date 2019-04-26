class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> Q;
        vector<vector<int> > v;
        if (!root) return v;
        Q.push(root);
        bool odd=false;
        while(!Q.empty()) {
            int count=Q.size();
            vector<int> t_v;
            while(count--) {
                TreeNode *node=Q.front();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                t_v.push_back(node->val);
                Q.pop();
            }
            if (odd) reverse(t_v.begin(), t_v.end());
            odd = !odd;
            v.push_back(t_v);
        }
        return v;
    }
};
