class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        up = 0
        p1, p2 = len(num1)-1, len(num2)-1
        ans = ''
        while p1 >= 0 or p2 >= 0:
            v1, v2 = 0, 0
            if p1 >= 0:
                v1 = ord(num1[p1]) - ord('0')
                p1 -= 1
            if p2 >= 0:
                v2 = ord(num2[p2]) - ord('0')
                p2 -= 1
            s = v1 + v2 + up
            up = s / 10
            ans = chr(s % 10 + ord('0')) + ans

        ans = chr(up + ord('0')) + ans if up else ans

        return ans

if __name__ == '__main__':
    num1 = '999'
    num2 = '1'
    print Solution().addStrings(num1, num2)
