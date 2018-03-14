class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        s = 1
        fac = 2
        while fac <= num / fac:
            if num % fac == 0:
                s += fac + num / fac
            fac += 1
        if s == num:
            return num > 1
        return False

if __name__ == '__main__':
    print Solution().checkPerfectNumber(28)
