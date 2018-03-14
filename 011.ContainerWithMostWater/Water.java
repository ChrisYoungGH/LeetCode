class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0, right = n - 1;
        int water = 0;

        while (left < right) {
            int h = Math.min(height[left], height[right]);
            water = Math.max(water, h * (right - left));
            while (left < right && height[left] <= h) left++;
            while (left < right && height[right] <= h) right--;
        }

        return water;
    }
}
