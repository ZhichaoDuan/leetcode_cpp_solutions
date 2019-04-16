class Solution {
public:
    double myPow(double x, int n) {
        double ans=1,base=x;
        long long m=labs(n);
        while(m!=0) {
            if (m&1!=0) {
                ans*=base;
            }
            base*=base;
            m>>=1;
        }

        if (n<0) return 1/ans;
        return ans;
    }
};
