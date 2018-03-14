public class DiffPair {
    public int findPairs(int[] nums, int k) {
        if (k < 0) {
            return 0;
        }

        Map<Integer, Integer> map = new HashMap<>();

        for (int n : nums) {
            if (!map.containsKey(n)) {
                map.put(n, 0);
            }
            map.put(n, map.get(n)+1);
        }

        int count = 0;

        if (k > 0) {
            for (int n : map.keySet()) {
                if (map.containsKey(n + k)) {
                    count++;
                }
            }
        }
        else {
            for (int v : map.values()) {
                if (v > 1) {
                    count++;
                }
            }
        }

        return count;
    }
}
