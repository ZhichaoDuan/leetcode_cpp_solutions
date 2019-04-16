class Solution {
public:
  int divide(int dividend, int divisor) {
    long res=0;
    bool negative=false;
    if ((dividend<0)^(divisor<0)) negative=true;
    dividend=labs(dividend);
    divisor=labs(divisor);

    long cnt=1;
    long t_dividend=dividend;
    long t_divisor=divisor;

    while (t_dividend>t_divisor) {
      cnt=1;
      while(t_dividend>=(t_divisor<<1)) {
        t_divisor=t_divisor<<1;
        cnt=cnt<<1;
      }
      res+=cnt;
      t_dividend=t_dividend-t_divisor;
      t_divisor=divisor;
    }

    if (negative) res*=-1;
    if (res>INT_MAX) res=INT_MAX;
    return res;
  }
};
