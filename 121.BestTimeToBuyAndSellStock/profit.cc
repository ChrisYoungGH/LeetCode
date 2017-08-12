class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int profit = 0;
        int max = prices[0], min = prices[0];
        for (int p : prices) {
            max = p > max ? p : max;
            if (p < min) {
                max = (min = p);
            }
            int diff = max - min;
            profit = diff > profit ? diff : profit;
        }

        return profit;
    }


    int maxProfitOpt(vector<int>& prices) {
        int minVal = INT_MAX;
        int profit = 0;
        for (int p : prices) {
            minVal = min(p, minVal);
            profit = max(p - minVal, profit);
        }
        return profit;
    }
};
