#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string base="1";
    if (n==1) return base;
    n--;
    while(n--) {
      base=genStr(base);
    }
    return base;
  }

  string toStr(int v) {
    stringstream ss;
    string res;
    ss<<v;
    ss>>res;
    return res;
  }

  string genStr(string s) {
    std::vector<string> v;
    int count=0;
    s+=".";
    for (size_t i = 0; i < s.length()-1; i++) {
      count++;
      if (s[i]!=s[i+1]) {
        v.push_back(toStr(count)+s[i]);
        count=0;
      }

    }
    string res="";
    for (string s : v) {
      res+=s;
    }
    return res;
  }
};
int main(int argc, char const *argv[]) {
  Solution sol;

  cout<<sol.countAndSay(5)<<endl;
  return 0;
}
