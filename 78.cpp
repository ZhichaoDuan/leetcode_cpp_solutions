class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> item;
        res.push_back(item);
        generate(0, nums, item ,res);
        return res;
    }
    
private:
    void generate(int i, std::vector<int>& nums, std::vector<int>& items, std::vector<std::vector<int>>&res) {
        if (i>=nums.size()) 
            return;
        items.push_back(nums[i]);
        res.push_back(items);
        generate(i+1, nums, items, res);
        items.pop_back();
        generate(i+1, nums, items, res);
    }
};
