class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i+len(needle)] == needle:
                return i

        return -1



if __name__ == '__main__':
    haystack = ""#'this is a book'
    needle = ""#'isa'
    print Solution().strStr(haystack, needle)
