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
        v[i][0]=v[i-2][0];
      }
    }

    for (size_t i = 1; i < s.length()+1; i++) {
      for (size_t j = 1; j < p.length()+1; j++) {
        if (p[j-1]=='.'||p[j-1]==s[i-1]) {
          v[j][i]=v[j-1][i-1];
        }
        else if(p[j-1]=='*'){
          if (p[j-2]==s[i-1]||p[j-2]=='.') {
            v[j][i]=v[j-2][i] || v[j][i-1];
          }
          else {
            v[j][i]=v[j-2][i];
          }
        }
      }
    }
    return v[p.length()][s.length()];
  }
};
