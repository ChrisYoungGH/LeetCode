class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ans = ''
        while n > 0:
            n -= 1
            ans = chr(n % 26 + ord('A')) + ans
            n /= 26
        return ans

if __name__ == '__main__':
    for i in range(1, 100):
        print i, Solution().convertToTitle(i)
