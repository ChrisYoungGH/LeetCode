class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        zigzagArr = ['' for row in range(numRows)]
        row = 0
        down = True
        for c in s:
            zigzagArr[row] += c

            # 判断方向
            if down and row + 1 == numRows:
                down = False
            if not down and row - 1 < 0:
                down = True

            # 判断是否增减行号
            if down and row + 1 < numRows:
                row += 1
            if not down and row - 1 >= 0:
                row -= 1

        ans = ''
        for row in zigzagArr:
            ans += row

        return ans


if __name__ == '__main__':
    s = 'AB'
    numRows = 1
    print Solution().convert(s, numRows)
