# -*- coding:utf-8 -*-


# python 正负数应分开，因为负数取模向上取整
class Solution(object):
    """docstring for reverse."""

    # 方法1：先转绝对值，再加上符号，最后判断是否在最大值和最小值范围内
    def reverse1(self, x):
        if x == 0:
            return 0

        MAX_INT = 2147483647    # self.maxInt(32)
        MIN_INT = -MAX_INT - 1

        flag = 1     # 正数
        if x < 0:
            flag = -1    # 负数
            x = -x

        revNum = 0
        while x != 0:
            revNum = revNum * 10 + x % 10
            x /= 10

        revNum *= flag
        if revNum > MAX_INT or revNum < MIN_INT:
            return 0
        return revNum

    # 方法2：有溢出的，符号变化，故只需比较符号位，即都右移31位后判断
    def reverse2(self, x):
        if x == 0:
            return 0

        sign = x >> 31

        flag = 1
        if x < 0:
            x = -x
            flag = -1

        res = 0
        while x != 0:
            res = res * 10 + x % 10
            x /= 10

        res *= flag
        x *= flag

        if res >> 31 == sign:
            return res
        return 0

    # 计算给定位数的最大整数
    def maxInt(self, nBits):
        b = 1
        sum = 0
        for i in range(nBits - 1):
            sum += b
            b <<= 1
        return sum


if __name__ == '__main__':
    # result = Solution().reverse2(-123)
    result = Solution().reverse2(-463847412)
    print result
