class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        if strs is None or len(strs) == 0:
            return ""

        if len(strs) == 1:
            return strs[0]

        minLen = min([len(str) for str in strs])
        longestIndex = 0
        repStr = strs[0]
        flag = True
        for c in repStr[:minLen]:
            for str in strs[1:]:
                if str[longestIndex] != c:
                    flag = False
                    break
            if not flag:
                break
            longestIndex += 1

        return longestIndex > 0 and repStr[:longestIndex] or ""


if __name__ == '__main__':
    strs = ['hello', 'hella', 'ahelly', 'helllllllllll']
    print Solution().longestCommonPrefix(strs)
