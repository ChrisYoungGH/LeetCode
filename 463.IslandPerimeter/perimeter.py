class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        perimeter = 0
        m = len(grid); n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    perimeter += 4
                    if i > 0   and grid[i-1][j] == 1: perimeter -= 1
                    if i < m-1 and grid[i+1][j] == 1: perimeter -= 1
                    if j > 0   and grid[i][j-1] == 1: perimeter -= 1
                    if j < n-1 and grid[i][j+1] == 1: perimeter -= 1
        return perimeter


if __name__ == '__main__':
    grid = [[0,1,0,0],
            [1,1,1,0],
            [0,1,0,0],
            [1,1,0,0]]
    print Solution().islandPerimeter(grid)
