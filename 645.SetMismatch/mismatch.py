class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        counts = [0] * len(nums)
        ans = []
        for n in nums:
            counts[n-1] += 1
            if counts[n-1] > 1:
                ans.append(n)

        for i in range(len(counts)):
            if counts[i] == 0:
                ans.append(i+1)

        return ans

if __name__ == '__main__':
    nums = [1,2,2,4]
    print Solution().findErrorNums(nums)
