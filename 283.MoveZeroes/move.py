# -*- coding: utf-8 -*-

class Solution(object):

    # 暴力法，模仿过程直接移动
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        tail = len(nums)
        i = 0
        while i < tail:
            if i > tail:
                break
            if nums[i] == 0:
                for j in range(i+1, tail):
                    nums[j-1] = nums[j]
                nums[tail-1] = 0
                tail -= 1
            else:
                i += 1

    # 计数法：统计到当前为止的非零元个数并赋值
    def moveZeroesOpt(self, nums):
        nNonZero = 0
        for n in nums:
            if n != 0:
                nums[nNonZero] = n
                nNonZero += 1
        for i in range(nNonZero, len(nums)):
            nums[i] = 0


if __name__ == '__main__':
    nums = [0,0,1]
    Solution().moveZeroesOpt(nums)
    print nums
