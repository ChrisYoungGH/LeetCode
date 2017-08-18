class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        unique1 = {}
        for n in nums1:
            unique1[n] = unique1.get(n, 0) + 1
        ans = []
        for n in nums2:
            if unique1.get(n, 0) > 0:
                ans.append(n)
                unique1[n] -= 1
        return ans

if __name__ == '__main__':
    nums1 = [1,2]
    nums2 = [1,1]
    print Solution().intersection(nums1, nums2)
