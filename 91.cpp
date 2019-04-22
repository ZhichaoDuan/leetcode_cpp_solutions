class Solution {
public:
  int numDecodings(string s) {
    int size=s.length();
    int curr=1;
    int prev=1;
    for (int i=1;i<s.length();i++) {
      int tmp=curr;
      if(s[i]=='0') {
        curr=prev;
        if (s[i-1]>='3'||s[i-1]<='0') return 0;
      }
      else{
        if (s[i-1]!='0'&&stoi(s.substr(i-1,2))<=26) {
          curr+=prev;
        }
      }
      prev=tmp;
    }
    return curr;
  }
};
