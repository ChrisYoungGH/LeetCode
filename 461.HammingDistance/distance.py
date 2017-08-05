class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z = x ^ y
        d = 0
        while z:
            d += z % 2
            z /= 2
        return d

if __name__ == '__main__':
    print Solution().hammingDistance(1,4)
