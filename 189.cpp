class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();
        vector<int>::iterator middle = begin+nums.size()-k;
        reverse(begin, middle);
        reverse(middle, end);
        reverse(begin, end);
    }
};
