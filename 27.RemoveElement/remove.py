# coding: utf-8 -*-

class Solution(object):
    # 将非目标值放到往前数目标值个数的位置
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        nTargets = 0
        for i in range(len(nums)):
            if nums[i] == val:
                nTargets += 1
            else:
                if nTargets != 0:
                    nums[i - nTargets] = nums[i]

        return len(nums) - nTargets

if __name__ == '__main__':
    nums = [2,3,2,2,3,4,3,1,1,6]
    print Solution().removeElement(nums, 3)
