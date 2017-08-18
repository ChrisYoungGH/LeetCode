class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (!count.containsKey(c)) {
                count.put(c, 0);
            }
            count.put(c, count.get(c)+1);
        }

        int sum = 0;
        int odd = 0;
        for (int v : count.values()) {
            sum += v;
            if (v % 2 != 0) {
                odd++;
            }
        }

        return sum - odd + Math.min(odd, 1);
    }
}
