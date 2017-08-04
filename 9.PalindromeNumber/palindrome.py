class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        xStr = str(x)
        length = len(xStr)
        for i in range(length / 2):
            if xStr[i] != xStr[length - i - 1]:
                return False
        return True


if __name__ == '__main__':
    x = 123321
    print Solution().isPalindrome(1321)
