class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 0:
            return False
        if num <= 1:
            return True
        root = 2
        while root <= num / root:
            if root * root == num:
                return True
            root += 1
        return False

if __name__ == '__main__':
    for i in range(101):
        if Solution().isPerfectSquare(i):
            print i
