public class Majority {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            int count = 0;
            if (map.containsKey(n)) {
                count = map.get(n);
            }
            count++;
            if (count > nums.length / 2) {
                return n;
            }
            map.put(n, count);
        }

        return 0;
    }
}
