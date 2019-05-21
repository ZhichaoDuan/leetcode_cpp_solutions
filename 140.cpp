class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return dfs(s,wordDict);
    }

    vector<string> dfs(string s, vector<string>& wordDict) {
        if (hash.count(s)>0) {
            return hash[s];
        }
        vector<string> v;
        if (find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()) {
            v.push_back(s);
        }
        for (int i=1;i<s.length();i++) {
            string first = s.substr(0,i);
            if (find(wordDict.begin(), wordDict.end(), first)!=wordDict.end()) {
                vector<string> ans = dfs(s.substr(i), wordDict);
                for (auto val:ans) {
                    v.push_back(first+" "+val);
                }
            }
        }
        hash[s]=v;
        return v;
    }

    unordered_map<string, vector<string>> hash;
};
