import collections

class Solution(object):
    # 用map存数，检查+k的值是否存在；对于k=0的情况检查是否多个值；k<0要考虑返回0
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 0:
            return 0

        numCnt = dict.fromkeys(nums, 0)
        for n in nums:
            numCnt[n] += 1

        count = 0
        keys = numCnt.keys()
        if k == 0:
            for n in keys:
                if numCnt[n] > 1:
                    count += 1
        else:
            for n in keys:
                if n + k in numCnt:
                    count += 1

        return count

    # 利用集合操作，nums与nums+k的交集
    def findPairs2(self, nums, k):
        if k > 0:
            return len(set(nums) & set(n + k for n in nums))
        if k == 0:
            return sum(v > 1 for v in collections.Counter(nums).values())
        return 0

if __name__ == '__main__':
    nums = [1, 3, 1, 5, 4]
    print(Solution().findPairs2(nums, 0))
