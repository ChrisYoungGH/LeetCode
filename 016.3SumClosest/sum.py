class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()

        ans = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            if i != 0 and nums[i] == nums[i-1]:
                continue

            l, r = i+1, len(nums)-1
            while l < r:
                s = nums[l] + nums[r] + nums[i]
                if s == target:
                    return s

                if abs(s - target) <  abs(ans - target):
                    ans = s
                    while l < r and nums[l] == nums[l+1]: l += 1
                    while l < r and nums[r] == nums[r-1]: r -= 1

                if s < target: l += 1
                else: r -= 1

        return ans

if __name__ == '__main__':
    nums = [-1,0,1,1,55]
    target = 3
    print Solution().threeSumClosest(nums, target)
