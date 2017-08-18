class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        ans = 0
        for p in points:
            d = {}
            for q in points:
                xd = p[0] - q[0]
                yd = p[1] - q[1]
                dist = xd * xd + yd * yd
                d[dist] = d.get(dist, 0) + 1
            for v in d.values():
                ans += v * (v-1)

        return ans
