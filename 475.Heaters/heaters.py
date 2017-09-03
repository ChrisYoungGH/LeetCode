class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters.sort()
        minRadius = 0
        for h in houses:
            minRadius = max(minRadius, self.distance(h, heaters))
        return minRadius

    def distance(self, h, heaters):
        low, high = 0, len(heaters)-1

        if h < heaters[low]:
            return heaters[low] - h
        if h > heaters[high]:
            return h - heaters[high]

        while True:
            mid = (low + high) / 2
            if heaters[mid] == h:
                return 0
            if high - low <= 1:
                return min(heaters[high] - h, h - heaters[low])
            if h > heaters[mid]:
                low = mid
            else:
                high = mid
