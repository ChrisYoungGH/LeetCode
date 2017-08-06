class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSubSum = sum = nums[0]
        for n in nums[1:]:
            sum = max(sum+n, n)
            maxSubSum = max(maxSubSum, sum)

        return maxSubSum

if __name__ == '__main__':
    print Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
