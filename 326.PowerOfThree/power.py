class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False;
        while n > 1:
            if n % 3:
                return False
            n /= 3
        return True

    ## 3^19为int内的最大3的次幂
    def isPowerOfThree2(self, n):
        return n > 0 and 1162261467 % n == 0

if __name__ == '__main__':
    print Solution().isPowerOfThree(27)
