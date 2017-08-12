class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ans = [0] * (rowIndex + 1)
        ans[0] = 1
        for i in range(rowIndex+1):
            for j in range(i, 0, -1):
                ans[j] += ans[j-1]
        return ans

if __name__ == '__main__':
    print Solution().getRow(3)
