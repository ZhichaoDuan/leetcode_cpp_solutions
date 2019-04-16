class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.size()==0) return res;
    deque<int> DQ;
    for (size_t i = 0; i < nums.size(); i++) {
      if (i>=k&&DQ.front()<=i-k) {
        DQ.pop_front();
      }
      while (!DQ.empty()&&nums[DQ.back()]<=nums[i]) {
        DQ.pop_back();
      }
      DQ.push_back(i);
      if (i>=k-1) {
        res.push_back(nums[DQ.front()]);
      }
    }
    return res;
  }
};
