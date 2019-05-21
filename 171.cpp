class Solution {
public:
    int titleToNumber(string s) {
        static const int factor = 26;
        unordered_map<char, int> translate;
        for (int i=0;i<26;i++){
            translate['A'+i]=i+1;
        }
        int times=0,res=0;
        for (int i=s.length()-1;i>=0;i--) {
            res += pow(factor, times)*translate[s[i]];
            times++;
        }
        return res;
    }
};
