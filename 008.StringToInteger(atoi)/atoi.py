import re
max_int = 2 ** 31 - 1
min_int = -max_int - 1

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # 1. 空字符串
        if not str:
            return 0

        # 2. 去除多余空格
        str = str.strip()

        # 3. 匹配是否满足格式，即左起连续的字符串可以形成一个数
        pattern = re.compile('[+-]?[0-9]+')
        match = pattern.match(str)
        if match:
            str = match.group()
        else:
            return 0

        # 4. 判断是否有符号
        if str[0] == '+' or str[0] == '-':
            left = 1
        else:
            left = 0

        # 5. 字符串转整数
        ans = 0
        for i in range(left, len(str)):
            ans = ans * 10 + (ord(str[i]) - ord('0'))

        # 6. 加上符号位（如果是负）
        if str[0] == '-':
            ans = -ans

        # 7. 判断是否溢出
        if ans > max_int:
            ans = max_int
        if ans < min_int:
            ans = min_int

        return ans

if __name__ == '__main__':
    print Solution().myAtoi("123")
