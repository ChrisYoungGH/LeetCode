class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max1 = max2 = max3 = -1001
        min1 = min2 = 1001
        for n in nums:
            if n > max1:
                max1, max2, max3 = n, max1, max2
            elif n > max2:
                max2, max3 = n, max2
            elif n > max3:
                max3 = n

            if n < min1:
                min1, min2 = n, min1
            elif n < min2:
                min2 = n

        return max(min1*min2, max2*max3) * max1

if __name__ == '__main__':
    nums = [1,2,3]
    print(Solution().maximumProduct(nums))
