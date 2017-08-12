class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not numbers:
            return []

        head, tail = 0, len(numbers) - 1
        while head < tail:
            sum = numbers[head] + numbers[tail]
            if sum == target:
                return [head+1, tail+1]
            if sum < target:
                head += 1
            else:
                tail -= 1

        return []

if __name__ == '__main__':
    print Solution().twoSum([2,7,11,15], 9)
