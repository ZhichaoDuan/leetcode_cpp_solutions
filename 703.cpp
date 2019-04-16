class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int> > Q;
  int k;
  vector<int> nums;
  KthLargest(int k, vector<int>& nums) {
    this->k=k;
    this->nums=nums;
    for (int i=0;i<nums.size();i++) {
      add(nums[i]);
    }
  }

  int add(int val) {
    if (Q.size()<k) {
      Q.push(val);
    }
    else {
      if (Q.top()<val) {
        Q.pop();
        Q.push(val);
      }
    }
    return Q.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
