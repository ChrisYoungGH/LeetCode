# -*- coding: utf-8 -*-
class Solution(object):
    # 方法1：直接找规律，运行时间反而比斐波那契快
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0

        count = 0
        for i in range(n/2+1):
            count += self.combination(n-i, i)

        return count

    def combination(self, n, k):
        if k > n/2:
            k = n - k

        ans = 1
        for i in range(n, n-k, -1):
            ans *= i
        for i in range(1, k+1):
            ans /= i

        return ans

    # 斐波那契数列，递归写法——超时！
    def climbStairs2(self, n):
        if n <= 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2
        return self.climbStairs2(n-1) + self.climbStairs2(n-2)

    # 斐波那契数列，循环写法——不超时，简洁！
    def climbStairs3(self, n):
        if n <= 0:
            return 0
        f1 = f2 = 1
        for i in range(n):
            f1, f2 = f2, f1 + f2
        return f1



if __name__ == '__main__':
    # for i in range(10):
    #     print i, Solution().climbStairs(i), Solution().climbStairs2(i)
    print Solution().climbStairs(35)
    print Solution().climbStairs2(35)
    print Solution().climbStairs3(35)
