class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        end = 1
        while True:
            if end >= len(s):
                return False

            substring = s[:end]
            subLength = len(substring)
            if len(s) % subLength != 0:
                end += 1
                continue

            flag = True
            for i in range(end, len(s), subLength):
                if s[i:i+subLength] != substring:
                    end += 1
                    flag = False
                    break

            if flag == True:
                return True

    def repeatedSubstringPatternOpt(self, s):
        if not s:
            return False

        ss = (s + s)[1:-1]

        return ss.find(s) != -1

if __name__ == '__main__':
    s = "abacababacab"
    print Solution().repeatedSubstringPatternOpt(s)
