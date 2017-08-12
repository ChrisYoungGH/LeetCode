# -*- coding: utf-8 -*-

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        profit = 0

        # 至少有2天才能完成一轮买进卖出的交易
        if not prices or n < 2:
            return profit

        flag = 1
        # 第一天：第二天涨则买(否则为平或跌，平则留到下一日判断买不买)
        if prices[0] < prices[1]:
            profit -= prices[0]
            flag = -1   # 买标记

        for i in range(1, n-1):
            if flag == -1:  #如果买了，关注什么时候卖
                # 直到下一日跌才卖
                if prices[i+1] < prices[i]:
                    profit += prices[i]
                    flag = 1    # 卖标记

            if flag == 1:   # 如果卖了，关注什么时候再买
                # 直到下一日涨才买
                if prices[i+1] > prices[i]:
                    profit -= prices[i]
                    flag = -1   # 买标记

        # 最后一天：不降则卖(平时卖出顺延到此处理；跌则上一个已抛)
        if flag == -1 and prices[n-1] >= prices[n-2]:
            profit += prices[n-1]

        return profit


    # 方法2：下一天比当天多则卖当天买下一天
    def maxProfitOpt(self, prices):
        return sum(max(prices[i+1] - prices[i], 0) for i in range(len(prices) - 1))


if __name__ == '__main__':
    print Solution().maxProfitOpt([9,8,7,6,10])
    # print Solution().maxProfit([1,9,6,9,1,7,1,1,5,9,9,9])
