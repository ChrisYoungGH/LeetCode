class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);

        int minRadius = 0;
        for (int h : houses) {
            minRadius = Math.max(minRadius, distance(h, heaters));
        }

        return minRadius;
    }

    public int distance(int h, int[] heaters) {
        int low = 0, high = heaters.length - 1;
        if (h < heaters[low]) {
            return heaters[low] - h;
        }
        if (h > heaters[high]) {
            return h - heaters[high];
        }

        while (true) {
            int mid = low + (high - low) / 2;
            if (heaters[mid] == h) {
                return 0;
            }
            if (high - low <= 1) {
                return Math.min(h - heaters[low], heaters[high] - h);
            }

            if (h > heaters[mid]) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
    }
}
