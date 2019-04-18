class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<bool> > v;
    for (size_t i = 0; i < p.length()+1; i++) {
      v.push_back(vector<bool>());
      for (size_t j = 0; j < s.length()+1; j++) {
        v[i].push_back(false);
      }
    }
    v[0][0]=true;
    for (size_t i = 1; i <= p.length(); i++) {
      if (p[i-1]=='*') {
        v[i][0]=v[i-1][0];
      }
    }

    for (size_t i = 1; i < p.length()+1; i++) {
      for (size_t j = 1; j < s.length()+1; j++) {
        if (p[i-1]==s[j-1]||p[i-1]=='?') {
          v[i][j]=v[i-1][j-1];
        }
        else if (p[i-1]=='*') {
          v[i][j] = v[i-1][j]||v[i][j-1];
        }
      }
    }
    return v[p.length()][s.length()];
  }
};
