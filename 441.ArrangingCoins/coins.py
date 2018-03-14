from math import sqrt

class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = int(sqrt(n * 2))
        return ans if ans * (ans + 1) / 2 <= n else ans - 1

if __name__ == '__main__':
    print Solution().arrangeCoins(1804289383)
