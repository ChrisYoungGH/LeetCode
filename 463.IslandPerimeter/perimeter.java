class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
             for (int j = 0; j < n; j++) {
                 if (grid[i][j] == 1) {
                     perimeter += 4;
                     if (i > 0 && grid[i-1][j] == 1) perimeter--;
                     if (i < m-1 && grid[i+1][j] == 1) perimeter--;
                     if (j > 0 && grid[i][j-1] == 1) perimeter--;
                     if (j < n-1 && grid[i][j+1] == 1) perimeter--;
                 }
             }
        }

        return perimeter;
    }
}
