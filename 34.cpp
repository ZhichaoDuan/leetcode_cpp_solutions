class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    std::vector<int> v{-1,-1};
    if (nums.empty()) {
      return v;
    }
    if (target<nums.front()||target>nums.back()) {
      return v;
    }
    int lhs=0,rhs=nums.size()-1,mid;
    while (lhs<=rhs) {
      mid=(lhs+rhs)/2;
      if (nums[mid]==target) break;
      else if(nums[mid]>target) rhs=mid-1;
      else lhs=mid+1;
    }
    if (lhs<=rhs) {
      lhs=mid-1;
      rhs=mid+1;
      while (lhs>=0&&nums[lhs]==target ) {
        lhs--;
      }
      while(rhs<nums.size()&&nums[rhs]==target) rhs++;
      v[0]=++lhs;
      v[1]=--rhs;
    }
    return v;
  }
};
