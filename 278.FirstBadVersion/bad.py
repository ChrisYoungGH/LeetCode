# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):
#
def isBadVersion(version):
    return False if version < 1702766719 else True;

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        while left <= right:
            mid = (left + right) / 2
            check = isBadVersion(mid)
            if check:
                if mid == 1 or not isBadVersion(mid-1):
                    return mid
                else:
                    right = mid - 1
            else:
                left = mid + 1

        return 0


if __name__ == '__main__':
    n = 2126753390
    print Solution().firstBadVersion(n)
