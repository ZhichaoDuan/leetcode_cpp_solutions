class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.size()==0) {
      return -1;
    }
    int left=0,right=nums.size()-1;
    int mid=0;
    while(left<=right) {
      mid=(left+right)/2;
      if (nums[mid]==target) {
        return mid;
      }
      if (nums[mid]>=nums[left]) {
        if (target<nums[mid]&&target>=nums[left]) {
          right=mid-1;
        } else {
          left=mid+1;
        }
      }
      else {
        if (target>nums[mid]&&target<=nums[right]) {
          left=mid+1;
        } else {
          right=right-1;
        }
      }
    }
    return -1;
  }
};
