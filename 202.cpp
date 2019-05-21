class Solution {
public:
    bool isHappy(int n) {
        if (n==0) return false;
        int squares = n;
        while(squares>=10) {
            int temp=0;
            while(squares) {
                temp += (squares%10)*(squares%10);
                squares = squares/10;
            }
            squares = temp;
        }

        if (squares==1||squares==7) return true;
        else return false;
    }
};
