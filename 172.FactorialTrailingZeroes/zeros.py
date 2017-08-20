class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        m = 5
        while m <= n:
        	ans += n / m
        	m *= 5
        return ans

if __name__ == '__main__':
	print Solution().trailingZeroes(23)