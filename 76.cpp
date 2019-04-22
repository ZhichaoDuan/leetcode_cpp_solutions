#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    if (!s.length()||!t.length()) return "";
    int count=0;
    string res="";
    int tArr[256]={0};
    for (char c : t) {
      tArr[c]++;
    }
    int sArr[256]={0};
    int minLen=INT_MAX;
    int begin,end,wbegin=0,wend=0;
    for (begin=0,end=0;end<s.length();end++) {
      if (tArr[s[end]]==0) continue;
      sArr[s[end]]++;
      if (sArr[s[end]]<=tArr[s[end]]) {
        count++;
      }
      if (count==t.length()) {
        while (tArr[s[begin]]==0||sArr[s[begin]]>tArr[s[begin]]) {
          if (sArr[s[begin]]>tArr[s[begin]]) sArr[s[begin]]--;
          begin++;
        }
        wbegin=begin;
        wend=end;
        if (wend-wbegin+1<minLen) {
          minLen=wend-wbegin+1;
          wend=end;
          wbegin=begin;
          res=s.substr(begin,end-begin+1);
        }
      }
    }
    return res;
  }
};
int main(int argc, char const *argv[]) {
  string a  ="dasdas";
  cout<<a.substr(0,3)<<endl;
  return 0;
}
