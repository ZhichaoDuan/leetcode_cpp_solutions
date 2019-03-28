class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;
        std::sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums,
                 std::vector<std::vector<int>> &result,
                 std::vector<int> &item,
                 std::set<std::vector<int>> &res_set,
                 int sum, int target) {
        if (i>=nums.size()||sum>target) {
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if (target==sum&&res_set.find(item)==res_set.end()) {
            result.push_back(item);
            res_set.insert(item);
                
        }
        
        generate(i+1, nums, result, item, res_set, sum, target);
        sum -= nums[i];
        item.pop_back();
        generate(i+1, nums, result, item, res_set, sum, target);
    } 
};
