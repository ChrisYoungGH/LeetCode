class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        flag = length = max = 0

        for i in range(len(nums)):
            if nums[i] == 1:
                if flag == 0:
                    flag = 1
                length += 1
            else:
                max = length > max and length or max
                length = 0
            max = length > max and length or max

        return max


if __name__ == '__main__':
    nums = [0]
    print(Solution().findMaxConsecutiveOnes(nums))
