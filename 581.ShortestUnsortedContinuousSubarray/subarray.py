class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        begin = 0; end = len(nums) - 1
        sortedNums = sorted(nums)

        while begin < len(nums):
            if nums[begin] == sortedNums[begin]:
                begin += 1
            else:
                break

        while end > begin:
            if nums[end] == sortedNums[end]:
                end -= 1
            else:
                break

        size = end - begin + 1
        return size != 1 and size or 0


    def findUnsortedSubarray2(self, nums):
        n = len(nums)
        begin = -1; end = -2
        maxVal = nums[0]; minVal = nums[n-1]
        for i in range(1,n):
            maxVal = max(nums[i], maxVal)
            minVal = min(nums[n-i-1], minVal)

            end = i if nums[i] < maxVal else end
            begin = n-i-1 if nums[n-i-1] > minVal else begin

        return end - begin + 1


if __name__ == '__main__':
    print(Solution().findUnsortedSubarray2([1,2,4,3,8,2,3,5]))
