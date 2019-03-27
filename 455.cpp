class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child=0;
        int cookies=0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        while(child<g.size()&&cookies<s.size()) {
            if (g[child]<=s[cookies]) {
                child++;
            }
            cookies++;
        }
        return child;
    }
};
