class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> S;
        std::string res = "";
        for (int i = 0; i<num.size(); i++) {
            int number = num[i] - '0';
            while(S.size() != 0 && number<S[S.size()-1]&&k>0) {
                S.pop_back();
                k--;
            }
            if (number!=0 || S.size()!=0) {
                S.push_back(number);
            }
        }
        
        while(S.size() != 0 && k > 0) {
            S.pop_back();
            k--;
        }
        
        for (int i=0; i<S.size(); i++) {
            res.append(1, '0'+S[i]);
        }
        
        if (res == "") {
            return "0";
        }
        return res;
    }
};
