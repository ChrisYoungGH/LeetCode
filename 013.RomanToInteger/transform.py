class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """

        dict = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        sum = 0
        for i in range(len(s) - 1):
            curr = dict[s[i]]
            next = dict[s[i+1]]
            if curr < next:
                sum -= curr
            else:
                sum += curr

        return sum + dict[s[len(s)-1]]


if __name__ == '__main__':
    print Solution().romanToInt("CMXCIX")
