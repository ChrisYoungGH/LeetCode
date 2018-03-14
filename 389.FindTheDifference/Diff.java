import java.util.*;

class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> letters = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (!letters.containsKey(c)) {
                letters.put(c, 0);
            }
            letters.put(c, letters.get(c)+1);
        }

        for (char c : t.toCharArray()) {
            if (!letters.containsKey(c) || letters.get(c) == 0) {
                return c;
            }
            letters.put(c, letters.get(c)-1);
        }
        return ' ';
    }
}
