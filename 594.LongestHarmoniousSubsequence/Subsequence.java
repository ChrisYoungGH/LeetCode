class Solution {
    public int findLHS(int[] nums) {
        Map<Integer,Integer> counts = new HashMap<>();
        for (int n : nums) {
            counts.put(n, counts.getOrDefault(n, 0) + 1);
        }

        int maxLen = 0;
        for (int key : counts.keySet()) {
            if (counts.containsKey(key-1)) {
                maxLen = Math.max(maxLen, counts.get(key-1) + counts.get(key));
            }

            if (counts.containsKey(key+1)) {
                maxLen = Math.max(maxLen, counts.get(key+1) + counts.get(key));
            }
        }

        return maxLen;
    }
}
