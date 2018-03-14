class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        strs = str.split(' ')
        if (len(pattern) != len(strs)):
            return False

        index = {}
        for i in range(len(pattern)):
            lastP = index.get(pattern[i]+'#', -1)
            lastS = index.get(strs[i], -1)
            if lastP != lastS:
                return False
            index[pattern[i]+'#'] = i
            index[strs[i]] = i

        return True

if __name__ == '__main__':
    pattern = 'abc'
    str = 'b c a'
    print Solution().wordPattern(pattern, str)
