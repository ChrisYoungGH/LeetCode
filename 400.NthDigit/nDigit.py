class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        k = base = 0
        while True:
            tmp = int(9 * k * (10 ** (k-1)))
            if base + tmp > n:
                break
            base += tmp
            k += 1

        remain = n - base
        num = -(-remain / k) + int(10 ** (k-1)) - 1
        nDigit = -remain % k
        print num, nDigit, k

        for i in range(nDigit+1):
            result = num % 10
            num /= 10

        return result


if __name__ == '__main__':
    print Solution().findNthDigit(1000000000)
