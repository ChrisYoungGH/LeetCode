class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n - 1

        while i > 0 and nums[i] <= nums[i-1]:
            i -= 1

        if i == 0:
            nums.sort()

        else:
            left = i - 1

            right, minmax = i, nums[i]
            for j in range(i+1, n):
                if nums[j] > nums[left]:
                    minmax = min(minmax, nums[j])
                    right = j

            tmp = nums[left]
            nums[left] = nums[right]
            nums[right] = tmp

            nums[i:] = sorted(nums[i:])
            # nums[i:] = nums[-1:i-1:-1]

if __name__ == '__main__':
    # nums = [1,2,1,5,4,3,3,2,1]
    nums = [1,2]
    Solution().nextPermutation(nums)
    print nums
