class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;
    int left=0,right=matrix[0].size()-1;
    int top=0, bottom=matrix.size()-1;
    while (left<right&&bottom>top) {
      for (size_t i = left; i < right; i++) {
        res.push_back(matrix[top][i]);
      }
      for (size_t i = top; i < bottom; i++) {
        res.push_back(matrix[i][right]);
      }
      for (size_t i = right; i > left; i--) {
        res.push_back(matrix[bottom][i]);
      }
      for (size_t i = bottom; i > top; i--) {
        res.push_back(matrix[i][left]);
      }
      left++;
      right--;
      top++;
      bottom--;
    }

    if (left==right) {
      for (size_t i = top; i <= bottom; i++) {
        res.push_back(matrix[i][left]);
      }
    }
    else if (top==bottom) {
      for (size_t i = left; i <= right; i++) {
        res.push_back(matrix[top][i]);
      }
    }
    return res;
  }
};
