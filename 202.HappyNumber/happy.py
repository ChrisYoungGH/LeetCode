class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        nums = {}
        while n > 1:
            if n in nums:
                return False
            nums[n] = 0
            tmp = n
            s = 0
            while tmp > 0:
                d = tmp % 10
                tmp //= 10
                s += d * d
            n = s

        return True

if __name__ == '__main__':
    n = 20
    print(Solution().isHappy(n))
