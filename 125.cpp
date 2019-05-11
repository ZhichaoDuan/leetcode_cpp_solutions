#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string s_ = "";
        for (char c : s) {
            if (isalnum(c)) {
                s_+=c;
            }
        }
        for (int i=0;i<s_.length();i++) {
            if (tolower(s_[i])!=tolower(s_[s_.length()-1-i])) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
  Solution sol;
  string a = "A man, a plan, a canal: Panama";
  cout<<sol.isPalindrome(a)<<endl;
  return 0;
}
