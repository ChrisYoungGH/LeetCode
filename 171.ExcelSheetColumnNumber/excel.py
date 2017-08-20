class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        digit = [ord(c)-ord('A')+1 for c in s]

        ans = 0
        for n in digit:
            ans = ans * 26 + n

        return ans

if __name__ == '__main__':
    print Solution().titleToNumber('A')
