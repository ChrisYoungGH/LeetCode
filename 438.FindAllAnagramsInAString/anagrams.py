# -*- coding: utf-8 -*-

import copy

class Solution(object):
    def findAnagramsTimeExceeded(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        letters = {}
        for c in p:
            letters[c] = letters.get(c, 0) + 1

        ans = []
        for i in range(len(s) - len(p) + 1):
            local_letters = copy.copy(letters)
            flag = True
            for j in range(i, i+len(p)):
                if s[j] not in local_letters or local_letters[s[j]] == 0:
                    flag = False
                    break
                local_letters[s[j]] -= 1
            if flag:
                ans.append(i)

        return ans


    def findAnagrams(self, s, p):
        # 统计子串字符
        letters = {}
        for c in p:
            letters[c] = letters.get(c, 0) + 1

        left = right = 0
        count = 0   # 计数窗口内合格字符数
        ans = []

        while right < len(s):
            # 先移动右指针，判断是否增加合格字符数
            c = s[right]
            if c in letters:
                letters[c] -= 1
                if letters[c] >= 0:
                    count += 1
            right += 1

            # 窗口合格字符数达到子串长度时，加入结果
            if count == len(p):
                ans.append(left)

            # 窗口大小达到子串长度时，移动左指针，判断是否减少合格字符数
            if right - left == len(p):
                c = s[left]
                if c in letters:
                    letters[c] += 1
                    if letters[c] > 0:
                        count -= 1
                left += 1

        return ans


if __name__ == '__main__':
    s = 'cbaebabacd'
    p = 'abc'
    print Solution().findAnagrams(s, p)
