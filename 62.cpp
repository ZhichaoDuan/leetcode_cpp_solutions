#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int> > v(m, vector<int>(n, 0));
    for (size_t i = 0; i < m; i++) {
      v[i][0]=1;
    }
    for (size_t i = 0; i < n; i++) {
      v[0][i]=1;
    }
    for (size_t i = 1; i < m; i++) {
      for (size_t j = 1; j < n; j++) {
        v[i][j]=v[i-1][j]+v[i][j-1];
      }
    }
    return v[m-1][n-1];
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  cout<<sol.uniquePaths(3,2)<<endl;;
  return 0;
}
