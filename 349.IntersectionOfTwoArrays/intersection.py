class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        unique1 = dict.fromkeys(nums1, 1)
        ans = []
        for n in nums2:
            if unique1.get(n, 0) == 1:
                ans.append(n)
                unique1[n] = 0
        return ans

if __name__ == '__main__':
    nums1 = [1,2,2,1,3]
    nums2 = [2,2,3]
    print Solution().intersection(nums1, nums2)
