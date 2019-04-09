class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr=0,i=0;
        while(i<nums.size()) {
            nums[curr]=nums[i];
            while(i<nums.size()&&nums[curr]==nums[i]) {
                i++;
            }
            
            curr++;
        }
        
        return curr;
    }
};
