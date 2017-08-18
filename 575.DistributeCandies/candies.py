class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        candyMap = {}
        for c in candies:
            candyMap[c] = candyMap.get(c, 0) + 1

        counts = sorted(candyMap.values())
        l = len(candies) / 2
        ans = 0
        for n in counts:
            ans += 1
            if ans >= l:
                break

        return ans


    def distributeCandies(self, candies):
        return min(len(set(candies)), len(candies) / 2)

if __name__ == '__main__':
    candies = [1,1,2,3]
    print Solution().distributeCandies(candies)
