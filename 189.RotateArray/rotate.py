class Solution(object):
    def rotate(self, nums, k):
        l = len(nums)
        k %= l
        if k == 0:
            return
        tmp = nums[-k:]
        nums[-l+k:] = nums[:l-k]
        nums[:k] = tmp


    def rotate2(self, nums, k):
        l = len(nums)
        k %= l
        self.reverse(nums, 0, l)
        self.reverse(nums, 0, k)
        self.reverse(nums, k, l)

    def reverse(self, nums, low, high):
        l = high - low
        for i in range(l/2):
            tmp = nums[low+i]
            nums[low+i] = nums[high-i-1]
            nums[high-i-1] = tmp


if __name__ == '__main__':
    nums = [-1]
    Solution().rotate2(nums, 2)
    print nums
