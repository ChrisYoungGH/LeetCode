import numpy as np

class Solution(object):
    def matrixReshape0(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if r * c != len(nums) * len(nums[0]):
            return nums

        # vec = []
        # for row in nums:
        #     vec.extend(row)
        # can be replace by one line below
        vec = sum(nums, [])

        res = []
        count = 0
        for i in range(r):
            row = []
            for j in range(c):
                row.append(vec[count])
                count += 1
            res.append(row)

        return res


    def matrixReshape1(self, nums, r,c):
        try:
            return np.reshape(nums, (r,c)).tolist()
        except:
            return nums


if __name__ == '__main__':
    nums = [[1,2], [3,4]]
    r = 1; c = 4
    print(Solution().matrixReshape1(nums, r, c))
