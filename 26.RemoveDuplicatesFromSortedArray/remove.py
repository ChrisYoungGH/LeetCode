# -*- coding: utf-8 -*-

class Solution(object):

    # 两个指针，一个指向新尾端，一个依次扫到数组尾
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums or len(nums) == 0:
            return 0

        lastIdx = 0
        currIdx = 0
        while True:
            while currIdx < len(nums) and nums[currIdx] == nums[lastIdx]:
                currIdx += 1
            if currIdx == len(nums):
                break
            lastIdx += 1
            nums[lastIdx] = nums[currIdx]

        # print nums[:lastIdx+1]

        return lastIdx + 1

    # 方法2: 只判断与新尾端相不相等，不相等则新尾端增加并改变值
    def removeDuplicates2(self, nums):
        if not nums:
            return 0

        newTail = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[newTail]:
                newTail += 1
                nums[newTail] = nums[i]

        return newTail + 1

    # 方法3：统计重复数，每遇到一个不重复的则写到其原来位置，即当前位置减去总重复数
    # 比较重复时与前一个数比较
    def removeDuplicates3(self, nums):
        if not nums:
            return 0

        nDups = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                nDups += 1
            else:
                nums[i - nDups] = nums[i]
        return len(nums) - nDups


if __name__ == '__main__':
    nums = [1,1,1,2,2,3,4,4,5,5,6,7,7,7,7,7,7,8]
    print Solution().removeDuplicates2(nums)
