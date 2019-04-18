class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > v;
    map<string, vector<string> > mp;
    for (int i=0;i<strs.size();i++) {
      string curr = strs[i];
      sort(curr.begin(), curr.end());
      if (mp.find(curr)==mp.end()) {
        mp[curr]=vector<string>();
      }
      mp[curr].push_back(strs[i]);
    }
    for (map<string, vector<string> >::iterator it=mp.begin(); it!=mp.end();++it) {
      v.push_back(it->second);
    }
    return v;
  }
};
