class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > v;
    if (nums.empty()) {
      return v;
    }
    vector<int> list;
    helper(v,list, nums, set<int>());
    return v;
  }
private:
  void helper(vector<vector<int> >& v, vector<int>& t, vector<int>& nums, set<int> st) {
    if (t.size()==nums.size()) {
      v.push_back(t) ;
    }
    else{
      for (size_t i = 0; i < nums.size(); i++) {
        if (st.find(nums[i])==st.end()) {
          t.push_back(nums[i]);
          st.insert(nums[i]);
          helper(v, t, nums, st);
          st.erase(nums[i]);
          t.pop_back();
        }
      }
    }
  }
};
