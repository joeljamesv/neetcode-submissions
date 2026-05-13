class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        if (prices.size() == 2) {
            if (prices[1] - prices[0] > 0)
                return prices[1] - prices[0];
            else
                return 0;
        }

        int buysOn = 0;
        int sellsOn = 1;
        int profit;
        int maxProfit = 0;
        while (1) {
            profit = prices[sellsOn] - prices[buysOn];

            if (profit <= 0) {
                buysOn = sellsOn;
                sellsOn = buysOn + 1;
            } else {
                if (profit > maxProfit) maxProfit = profit;

                sellsOn++;
            }

            if (sellsOn >= prices.size()) break;
        }
        return maxProfit;
    }
};
