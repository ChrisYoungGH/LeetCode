class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        water = 0
        left, right = 0, n-1
        while left < right:
            h = min(height[left], height[right])
            water = max(water, h * (right - left))
            while left < right and height[left] <= h:
                left += 1
            while left < right and height[right] <= h:
                right -= 1

        return water

if __name__ == '__main__':
    height = [1,2,4,3]
    print Solution().maxArea(height)
