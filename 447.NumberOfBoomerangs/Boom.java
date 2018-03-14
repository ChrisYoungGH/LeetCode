class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0;
        for (int[] p : points) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int[] q : points) {
                int x = p[0] - q[0];
                int y = p[1] - q[1];
                int dist = x * x + y * y;
                map.put(dist, map.getOrDefault(dist, 0) + 1);
            }

            for (Integer v : map.values()) {
                ans += v * (v-1);
            }
        }
        
        return ans;
    }
}
