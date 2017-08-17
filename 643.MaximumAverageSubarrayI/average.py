class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        maxSum = sumVal = sum(nums[:k])
        for i in range(len(nums) - k):
            sumVal += -nums[i] + nums[i+k]
            maxSum = max(maxSum, sumVal)

        return maxSum / k

if __name__ == '__main__':
    nums = [1,12,-5,-6,50,3]
    print(Solution().findMaxAverage(nums, 4))
