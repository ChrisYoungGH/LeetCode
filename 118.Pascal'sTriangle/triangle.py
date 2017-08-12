import copy

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows <= 0:
            return []
        ans = [[1]]
        for i in range(1,numRows):
            ans.append([1])
            prev = ans[i-1]
            curr = ans[i]
            for j in range(1, i):
                curr.append(prev[j-1] + prev[j])
            curr.append(1)

        return ans

if __name__ == '__main__':
    print Solution().generate(5)
