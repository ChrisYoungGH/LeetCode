class Solution(object):
    # Time limit exceeded
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        unique = set()
        for i in range(len(nums) - 2):
            s = -nums[i]
            m = {}
            for j in range(i+1, len(nums)):
                if nums[j] in m:
                    solution = [nums[i], -nums[i] - nums[j], nums[j]]
                    sorted_solution = tuple(sorted(solution))
                    if sorted_solution not in unique:
                        unique.add(sorted_solution)
                        ans.append(solution)
                    m[nums[j]] -= 1
                else:
                    m[s - nums[j]] = 1

        return ans


    def threeSum2(self, nums):
        nums.sort()
        ans = []
        for i in range(len(nums)):
            if i != 0 and nums[i] == nums[i-1]:
                continue
            s = -nums[i]
            l, h = i + 1, len(nums) - 1
            while l < h:
                if nums[l] + nums[h] == s:
                    ans.append([nums[i], nums[l], nums[h]])
                    while l < h and nums[l+1] == nums[l]:
                        l += 1
                    l += 1
                    while l < h and nums[h-1] == nums[h]:
                        h -= 1
                    h -= 1
                elif nums[l] + nums[h] < s:
                    l += 1
                else:
                    h -= 1
        return ans

if __name__ == '__main__':
    nums = [-1, -1, -1, 0, 1, 2, 2, 2, -1, 4]
    print Solution().threeSum2(nums)
