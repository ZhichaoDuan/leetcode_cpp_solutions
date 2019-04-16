#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string removeKdigits(string num, int k) {
    int sz = num.size();
    if (sz==k) {
      return "0";
    }
    std::vector<char> v;
    for (char c : num)  {
      while (!v.empty()&&v.back()>c&&k>0) {
        v.pop_back();k--;
      }
      v.push_back(c);
    }

    while(k--) v.pop_back();
    string res="";
    for (char c : v) res+=c;
    int i=0;
    for (;i<res.length();i++) {
      if (res[i]!='0') break;
    }
    res=res.substr(i);
    if (res.length()==0) return "0";
    return res;
  }
};

int main()
{
  Solution sol;
  cout<<sol.removeKdigits("10", 1)<<endl;
  return 0;
}
