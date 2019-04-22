class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size()<1) {
      return ;
    }
    bool frz=false, fcz=false;
    for (size_t i = 0; i < matrix[0].size(); i++) {
      if (matrix[0][i]==0) {
        frz=true;
        break;
      }
    }
    for (size_t i = 0; i < matrix.size(); i++) {
      if (matrix[i][0]==0) {
        fcz=true;
        break;
      }
    }

    for (int x=1;x<matrix[0].size();x++) {
      for (int y=1;y<matrix.size();y++) {
        if (matrix[y][x]==0)  {
          matrix[y][0]=0;
          matrix[0][x]=0;
        }
      }
    }

    for (int i=1;i<matrix[0].size();i++) {
      if (matrix[0][i]==0)  {
        for (int j=1;j<matrix.size();j++) matrix[j][i]=0;
      }
    }

    for (int i=1;i<matrix.size();i++) {
      if (matrix[i][0]==0)  {
        for (int j=1;j<matrix[0].size();j++) matrix[i][j]=0;
      }
    }
    if (frz) for (int i=0;i<matrix[0].size();i++) matrix[0][i]=0;
    if (fcz) for (int i=0;i<matrix.size();i++) matrix[i][0]=0;
  }
};
