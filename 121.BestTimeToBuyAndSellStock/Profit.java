import java.util.*;

public class Profit {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
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

    public int maxProfitOpt(int[] prices) {
        int minVal = Integer.MAX_VALUE;
        int profit = 0;
        for (int p : prices) {
            minVal = Math.min(p, minVal);
            profit = Math.max(p - minVal, profit);
        }
        return profit;
    }

    public static void main(String[] args) {
        int[] prices = new int[]{7,1,5,3,6,4};
        System.out.println(new Profit().maxProfit(prices));
    }
}
