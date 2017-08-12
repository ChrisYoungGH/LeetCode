public class Buy {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int profit = 0;
        int flag = 1;    // 初始为已卖状态

        if (prices == null || n < 2) {
            return profit;
        }

        // 第一天，如果第二天是涨才买，否则等第二天再判断
        if (prices[0] < prices[1]) {
            profit -= prices[0];
            flag = -1;
        }

        for (int i = 1; i < n-1; i++) {
            // 如果买了，直到下一日跌才卖
            if (flag == -1 && prices[i+1] < prices[i]) {
                profit += prices[i];
                flag = 1;
            }
            // 如果卖了，直到下一日涨才买
            if (flag == 1 && prices[i+1] > prices[i]) {
                profit -= prices[i];
                flag = -1;
            }
        }

        // 最后一天，如果已买并且不跌就意味着还没卖，需要卖掉
        if (flag == -1 && prices[n-1] >= prices[n-2]) {
            profit += prices[n-1];
        }

        return profit;
    }

    public int maxProfitOpt(int[] prices) {
        int sum = 0;
        for (int i = 0; i < prices.length-1; i++) {
            sum += Math.max(prices[i+1] - prices[i], 0);
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(new Buy().maxProfitOpt(new int[]{2,1,4,6}));
    }
}
