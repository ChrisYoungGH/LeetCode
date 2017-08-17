class Solution(object):
    def singleNumber1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        for n in nums:
            d[n] = d.get(n, 0) + 1
        for k,v in d.items():
            if v == 1:
                return k


    def singleNumber2(self, nums):
        ans = 0
        for n in nums:
            ans ^= n
        return ans

if __name__ == '__main__':
    nums = [2,2,3,1,3,1,4]
    print(Solution().singleNumber2(nums))
