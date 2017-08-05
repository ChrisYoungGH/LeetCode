class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n < 1:
            return ""

        curr = "1"
        for i in range(n-1):
            curr = self.read(curr)

        return curr


    def read(self, seq):
        if not seq:
            return ""

        ans = ""
        digit = seq[0]
        count = 1
        for num in seq[1:]:
            if num == digit:
                count += 1
            else:
                ans += str(count) + digit
                digit = num
                count = 1
        ans += str(count) + digit

        return ans


if __name__ == '__main__':
    print Solution().countAndSay(5)
