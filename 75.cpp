class Solution {
public:
  void sortColors(vector<int>& nums) {
    if (nums.size()<=1) return;
    int i=0,j=0,k=nums.size()-1;
    while (j<=k) {
      if (nums[j]==0) swap(nums, i++, j++);
      else if(nums[j]==1) j++;
      else swap(nums, j, k--);
    }
  }
private:
  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
  }
};
