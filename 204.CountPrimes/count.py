from math import sqrt

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2: return 0

        primes = [1] * n
        primes[0] = primes[1] = 0

        for i in range(2, int(n**0.5)+1):
            if primes[i]:
                primes[i*i:n:i] = [0] * len(primes[i*i:n:i])

        return sum(primes)


if __name__ == '__main__':
    n = 14
    print(Solution().countPrimes(n))
