class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_ = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0];
        for (int i=1; i<nums.size();i++) {
            int next_max = curr_max * nums[i];
            int next_min = curr_min * nums[i];
            curr_max = max(nums[i], max(next_max, next_min));
            curr_min = min(nums[i], min(next_min, next_max));
            max_ = max(max_, curr_max);
        }
        return max_;
    }
};