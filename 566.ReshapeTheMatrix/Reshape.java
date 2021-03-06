public class Reshape {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int n = nums.length, m = nums[0].length;

        if (r * c != n * m) {
            return nums;
        }

        int[][] ans = new int[r][c];
        for (int i = 0; i < r * c; i++) {
            ans[i/c][i%c] = nums[i/m][i%m];
        }

        return ans;
    }
}
