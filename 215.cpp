class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > Q;
        for (int num:nums) {
            if (Q.size()<k) {
                Q.push(num);
            } else if (Q.size()==k) {
                if (Q.top()<num) {
                    Q.pop();
                    Q.push(num);
                }
            }
        }
        return Q.top();
    }
};