# -*- coding: utf-8 -*-
class Solution(object):
    # 方法1：数目相等，右括号匹配完毕
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        if len(s) % 2:
            return False

        seq = list(s)
        stack = []
        left = ['(', '[', '{']
        right = {')': '(', ']': '[', '}': '{'}
        count = dict.fromkeys(['(', ')', '[', ']', '{', '}'], 0)

        for p in seq:
            # 统计括号数
            count[p] += 1
            # 左括号入栈
            if p in left:
                stack.append(p)
            # 右括号匹配弹出栈顶
            else:
                if stack and stack[-1] == right[p]:
                    stack.pop()

        # 计算左右括号数目是否匹配
        if count['('] - count[')'] != 0 \
            or count['['] - count[']'] != 0 \
                or count['{'] - count['}'] != 0:
            return False

        if not stack:
            return True
        return False

    # 方法2：每个右括号都要与当前栈顶匹配，否则为非法
    def isValidOpt(self, s):
        stack = []
        par = {'(': ')', '[': ']', '{': '}'}
        for c in s:
            if c in par.keys():
                stack.append(c)
            elif c in par.values() and (not stack or par[stack.pop()] != c):
                return False

        return not stack


if __name__ == '__main__':
    s = '()'
    print Solution().isValidOpt(s)
