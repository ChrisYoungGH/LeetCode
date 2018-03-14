class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counts = {}
        for n in nums:
            counts[n] = counts.get(n, 0) + 1

        keys = counts.keys()

        maxlen = 0
        for key in keys:
            if key - 1 in counts:
                maxlen = max(maxlen, counts[key-1] + counts[key])
            if key + 1 in counts:
                maxlen = max(maxlen, counts[key+1] + counts[key])

        return maxlen

if __name__ == '__main__':
    nums = [1,3,2,2,5,2,3,7]
    print Solution().findLHS(nums)
