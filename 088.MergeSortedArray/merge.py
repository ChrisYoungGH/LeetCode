class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1
        p2 = n - 1
        idx = m + n - 1
        while p1 >= 0 and p2 >= 0:
            if (nums1[p1] > nums2[p2]):
                nums1[idx] = nums1[p1]
                p1 -= 1
            else:
                nums1[idx] = nums2[p2]
                p2 -= 1
            idx -= 1
        while p2 >= 0:
            nums1[idx] = nums2[p2]
            idx -= 1
            p2 -= 1


if __name__ == '__main__':
    nums1 = [1,3,5,7,0,0,0]
    nums2 = [2,4,6]
    Solution().merge(nums1, 4, nums2, 3)
    print(nums1)
