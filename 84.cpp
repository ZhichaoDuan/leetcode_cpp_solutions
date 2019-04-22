class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int res=0;
    stack<int> stk;
    for (int i=0;i<heights.size();i++) {
      if (stk.empty()||stk.top()<=heights[i]) stk.push(heights[i]);
      else {
        int count=0;
        while(!stk.empty()&&stk.top()>heights[i]) {
          count++;
          res=max(res,stk.top()*count);
          stk.pop();
        }
        while(count--) {stk.push(heights[i]);}
        stk.push(heights[i]);
      }
    }
    int count=1;
    while(!stk.empty()) {
      res=max(res,stk.top()*count);
      stk.pop();
      count++;
    }
    return res;
  }
};
