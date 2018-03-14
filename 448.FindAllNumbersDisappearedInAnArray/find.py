class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for n in nums:
            index = abs(n) - 1
            if nums[index] > 0:
                nums[index] = -nums[index]

        ans = []
        for i in range(len(nums)):
            if nums[i] > 0:
                ans.append(i+1)

        return ans

if __name__ == '__main__':
	nums = [4,3,2,7,8,2,3,1]
	print(Solution().findDisappearedNumbers(nums))
