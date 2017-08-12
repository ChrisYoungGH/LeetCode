# -*- coding: utf-8 -*-
#
class Solution(object):
    # 方法1：求和再减
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = sum(nums)
        n = len(nums)
        return n*(n+1)/2 -s

    # 方法2：a^b^b=a
    def missingNumberOpt(self, nums):
        res = len(nums)
        for i in range(len(nums)):
            res ^= i ^ nums[i]
        return res

if __name__ == '__main__':
    print Solution().missingNumberOpt([3,2,0])
