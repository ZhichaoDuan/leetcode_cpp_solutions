class Solution {
public:
  bool canJump(vector<int>& nums) {
    int maxpos=0;
    for (size_t i = 0; i < nums.size()-1; i++) {
      maxpos=max(maxpos,i+nums[i]);
      if (maxpos==i) {
        return false;
      }
    }
    return true;
  }
};
