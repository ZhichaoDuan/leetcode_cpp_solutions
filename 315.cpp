#include <bits/stdc++.h>
using namespace std;
class TN {
public:
    int val;
    int count;
    TN *left;
    TN *right;
    TN(int v) : val(v), left(NULL), right(NULL), count(1) {}
};

class Solution {
public:
    TN *root;
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.size()==0) return res;
        
        root = new TN(nums[nums.size()-1]);
        res.push_back(0);
        for (int i=nums.size()-2;i>=0;i--) {
            int c = insert_node(*root, nums[i]);
            res.push_back(c);
        }
        reverse(res.begin(), res.end());
        return res;
    }   

    int insert_node(TN &root, int val) {
        TN *node = &root;
        int t_count = 0;
        while(true) {
            if (val <= node->val) {
                node->count++;
                // cout<<node->left->val<<"asd"<<endl;
                if (node->left==NULL) {
                    node->left = new TN(val);
                    break;
                } else {
                    node = node->left;
                }
            } else {
                t_count += node->count;
                if (node->right==NULL) {              
                    node->right = new TN(val);                        
                    break;
                } else {                    
                    node = node->right;
                }
            }
            
        }

        return t_count;
    }
    
};



int main() {
    vector<int> v({5, 2, 6, 1});
    Solution sol;
    vector<int> res =  sol.countSmaller(v);
    cout<<"haha"<<res[0]<<res[1]<<res[2]<<res[3]<<endl;
    return 0;
}

