class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        l = len(flowerbed)
        for i in range(l):
            if flowerbed[i] == 1:
                if i-1 >= 0:
                    flowerbed[i-1] = -1
                if i+1 < l:
                    flowerbed[i+1] = -1

        count = 0
        for i in range(l):
            if flowerbed[i] == 0:
                count += 1
                if i+1 < l:
                    flowerbed[i+1] = 1

        return count >= n

if __name__ == '__main__':
    print(Solution().canPlaceFlowers([0,1,0], 1))
