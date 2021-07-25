class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> buy(size, 0);
        vector<int> sell(size, 0);
        vector<int> rest(size, 0);
        buy[0] = -prices[0];
        
        for(int i = 1; i < size; i++)
        {
            buy[i] = max( rest[i - 1] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
            // Because buy[i] = max( rest[i - 1] - prices[i], buy[i - 1]);
            // So: rest[i] = max(buy[i - 1], max(sell[i - 1], rest[i - 1])) can be simplified to 
            rest[i] = max(sell[i - 1], rest[i - 1]);
        }

        return max(rest[size - 1], sell[size - 1]);
        
    }
};