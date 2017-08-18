class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        letters = {}
        for c in s:
            letters[c] = letters.get(c, 0) + 1

        for c in t:
            if letters.get(c, 0) == 0:
                return c
            letters[c] -= 1


if __name__ == '__main__':
    s = 'abcd'
    t = 'bcdea'
    print Solution().findTheDifference(s, t)
