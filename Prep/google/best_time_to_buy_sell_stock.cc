class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[buy]) buy = i;
            max_profit = max(max_profit, prices[i] - prices[buy]);
        }
        return max_profit;
    }
};
