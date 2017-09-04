class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count1 = count2 = 0
        n = len(nums)
        for i in range(n - 2):
            if nums[i] > nums[i+1]:
                count1 += 1
                if count1 > 1:
                    return False
            if nums[i] > nums[i+2]:
                count2 += 1
                if count2 > 1:
                    return False
        if nums[n-2] > nums[n-1]:
            count1 += 1
        if count1 > 1 or count2 > 1:
            return False
        return True
