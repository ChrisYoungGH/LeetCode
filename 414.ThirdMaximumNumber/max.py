class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max1 = max2 = max3 = -float('inf')
        for n in nums:
            if n > max1:
                max3, max2, max1 = max2, max1, n
            elif n == max1:
                continue
            elif n > max2:
                max3, max2 = max2, n
            elif n == max2:
                continue
            elif n > max3:
                max3 = n

        if max3 > -float('inf'):
            return max3
        return max1


if __name__ == '__main__':
    nums = [3,3,4,3,4,3,0,3,3]
    print Solution().thirdMax(nums)
