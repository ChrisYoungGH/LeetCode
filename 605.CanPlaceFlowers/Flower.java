public class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int l = flowerbed.length;

        for (int i = 0; i < l; i++) {
            if (flowerbed[i] == 1) {
                if (i-1 >= 0) {
                    flowerbed[i-1] = -1;
                }
                if (i+1 < l) {
                    flowerbed[i+1] = -1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < l; i++) {
            if (flowerbed[i] == 0) {
                count++;
                if (i+1 < l) {
                    flowerbed[i+1] = 1;
                }
            }
        }

        return count >= n;
    }
}
