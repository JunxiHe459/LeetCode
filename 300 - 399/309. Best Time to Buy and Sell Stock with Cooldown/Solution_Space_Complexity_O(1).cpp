class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_buy;
        int buy = -prices[0];
        int sell = 0;
        int prev_sell = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            prev_buy = buy;
            buy = max(prev_sell - prices[i], prev_buy);
            
            prev_sell = sell;
            sell = max(prev_buy + prices[i], prev_sell);
        }
        
        return sell;
    }
};