class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<string> > res;
        std::vector<string> v;
        DFS(res, v, 0, s);
        return res;
    }

    void DFS(vector<vector<string>>& res, vector<string>& v, int idx, string s) {
        if (idx==s.length()) {
            res.push_back(v);
            return ;
        }
        for (size_t i = idx; i < s.length(); i++) {
            if (isPalindrome(s.substr(idx, i-idx+1))) {
                v.push_back(s.substr(idx, i-idx+1));
                DFS(res, v, i+1, s);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        for (size_t i = 0; i < s.length()/2; i++) {
            if (s[i]!=s[s.length()-i-1]) {
                return false;
            }
        }
        return true;
    }
};
