class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;
        std::sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums,
                  std::vector<std::vector<int>> &result ,
                  std::vector<int>& items, 
                  std::set<std::vector<int>>& res_set) {
        if (i>=nums.size())
            return;
        items.push_back(nums[i]);
        if (res_set.find(items) == res_set.end()) {
            result.push_back(items);
            res_set.insert(items);
        }
        generate(i+1, nums, result, items, res_set);
        items.pop_back();
        generate(i+1, nums, result, items, res_set);
            
    }
};
