class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ = INT_MAX;
        int max_profit = 0;
        for (int n : prices) {
            min_ = min(min_,n);
            max_profit = max(max_profit, n-min_);
        }
        return max_profit;
    }
};
