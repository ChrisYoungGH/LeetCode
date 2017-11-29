class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):

        bits = [0] * 32
        m = 0
        while n > 0:
            bits[m] = n % 2
            n /= 2
            m += 1

        print(bits)

        res = 0
        for i in range(len(bits)):
            res = res * 2 + bits[i]

        return res

if __name__ == '__main__':
    print(Solution().reverseBits(2147483648))
