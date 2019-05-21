class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> record;
        for(int num : nums) {
            record[num]++;
            if (record[num]>1) return true;
        }
        return false;
    }
};
