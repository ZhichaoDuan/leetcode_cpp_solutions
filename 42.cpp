class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty()||height.size()<3) {
      return 0;
    }
    int res = 0;
    int leftmost=0, rightmost=0;
    int i=0,j=height.size()-1;
    while(i<=j) {
      leftmost=max(leftmost, height[i]);
      rightmost=max(rightmost, height[j]);
      if (leftmost<rightmost) {
        res+=leftmost-height[i];
        i++;
      }
      else{
        res+=rightmost-height[j];
        j--;
      }
    }
    return res;

  }
};
