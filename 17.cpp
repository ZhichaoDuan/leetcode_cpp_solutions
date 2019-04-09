class Solution {
public:
    vector<string> letterCombinations(string digits) {       
        
        if (digits.length() == 0)
            return std::vector<string>();
        
        std::map<char, std::string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        
        std::vector<string> result;
        helper(digits, 0, "", result, map);
        return result;
    }
    
private:
    void helper(string digits, int idx, std::string curr, std::vector<string> &result,
                std::map<char, std::string> map) {
        if (idx >= digits.length()) {
        	result.push_back(curr);
            return ;
        }
        
        std::string tmp = map[digits[idx]];
		idx+=1; 
        for (int i=0;i<tmp.length();i++) {       	
            helper(digits, idx, curr+tmp[i], result, map);
        }
    }
};
