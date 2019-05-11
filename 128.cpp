class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for (int num : nums) {
            int temp=1;
            if (!s.count(num-1)) {
                while(s.count(++num)) {
                    temp+=1;
                }
                ans=max(temp,ans);
            }
        }
        return ans;
    }
};
