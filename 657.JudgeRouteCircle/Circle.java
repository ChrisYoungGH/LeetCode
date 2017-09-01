class Solution {
    public boolean judgeCircle(String moves) {
        Map<Character, Integer> counts = new HashMap<Character, Integer>() {
            {
                put('U', 0);
                put('D', 0);
                put('L', 0);
                put('R', 0);
            }
        };
        for (char c : moves.toCharArray()) {
            counts.put(c, counts.get(c) + 1);
        }
        if (counts.get('U').equals(counts.get('D')) && counts.get('L').equals(counts.get('R'))) {
            return true;
        }
        return false;
    }
}
