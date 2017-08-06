class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        low = 0
        high = x
        while low <= high:
            mid = (low + high) / 2
            square = mid * mid
            if square == x:
                return mid
            if square < x:
                low = mid + 1
            else:
                high = mid - 1

        return square <= x and mid or mid-1

if __name__ == '__main__':
    print Solution().mySqrt(1025)
