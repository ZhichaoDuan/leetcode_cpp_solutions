#include "bits/stdc++.h"
#include "utils.cpp"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, 0);
        dp[0]=1;
        for (size_t i = 1; i <= s.length(); i++) {
            for (size_t j = i; j > 0; j--) {
                string sub = s.substr(i-j, j);
                if (find(wordDict.begin(),wordDict.end(),sub)!=wordDict.end()) {
                    if (dp[i-j]==1) {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
int main(int argc, char const *argv[]) {
    Solution sol;
    string s = "applepenapple";
    string ss[] = {"apple", "pen"};
    vector<string> v=arrayToVector(ss, 2);
    sol.wordBreak(s, v);
    return 0;
}
