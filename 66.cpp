class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    digits.insert(digits.begin(),0);
    int fixer=0;
    int idx=digits.size()-1;
    do {
      int tmp = digits[idx]+1;
      fixer=tmp/10;
      digits[idx]=tmp%10;
      idx--;

    } while(fixer!=0);
    if (digits[0]!=0) return digits;
    else digits.erase(digits.begin()); return digits;
  }
};
