class Solution {
public:
  int mySqrt(int x) {
    int res=0;
    int add=1;
    int curr=0;
    while (curr<=x) {
      if (INT_MAX-curr<add) {
        return res;
      }
      curr+=add;
      res++;
      add+=2;
    }
    return res-1;
  }
};
