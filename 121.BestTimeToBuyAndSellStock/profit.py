class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0

        max = min = prices[0]
        profit = 0
        for p in prices:
            max = p > max and p or max
            if p < min:
                max = min = p
            diff = max - min
            profit = diff > profit and diff or profit

        return profit


    def maxProfitOpt(self, prices):
        minVal = float('inf')
        profit = 0
        for p in prices:
            minVal = min(minVal, p)
            profit = max(profit, p-minVal)

        return profit

if __name__ == '__main__':
    print Solution().maxProfitOpt([7,1,5,3,6,4])
