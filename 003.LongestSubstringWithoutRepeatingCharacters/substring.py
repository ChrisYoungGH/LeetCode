class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlen = 0
        left = right = 0
        for i in range(len(s)):
            # 寻找当前值是否与窗口内重复
            repeat = False
            for j in range(left, i):
                if s[i] == s[j]:
                    repeat = True
                    break
            # 更新左端和全局最大值
            if repeat:
                maxlen = max(maxlen, right - left)
                left = j + 1
            # 右端总是增加
            right += 1

        return max(maxlen, right - left)

if __name__ == '__main__':
    s = 'c'
    print Solution().lengthOfLongestSubstring(s)
