class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> map;
        std::vector<int> res;
        for (int i=0;i<nums.size();i++)
            map[nums[i]]=i;
        for (int i=0; i<nums.size(); i++)
        {
            int rest = target-nums[i];
            if (map.find(rest) != map.end() && map[rest] != i) {
                res.push_back(i);
                res.push_back(map[rest]);
                break;
            }
        }
        return res;
    }
};
