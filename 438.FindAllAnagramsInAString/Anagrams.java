import java.util.*;

class Anagrams {
    public List<Integer> findAnagrams(String s, String p) {
        Map<Character, Integer> letters = new HashMap<Character, Integer>();
        for (char c : p.toCharArray()) {
            letters.put(c, letters.getOrDefault(c, 0) + 1);
        }

        int left = 0, right = 0;
        int count = 0;
        List<Integer> ans = new ArrayList<Integer>();

        while (right < s.length()) {
            char c1 = s.charAt(right);
            if (letters.containsKey(c1)) {
                letters.put(c1, letters.get(c1) - 1);
                if (letters.get(c1) >= 0) {
                    count++;
                }
            }
            right++;

            if (count == p.length()) {
                ans.add(left);
            }

            if (right - left == p.length()) {
                char c2 = s.charAt(left);
                if (letters.containsKey(c2)) {
                    letters.put(c2, letters.get(c2) + 1);
                    if (letters.get(c2) > 0) {
                        count--;
                    }
                }
                left++;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        String s = "cbaebabacd", t = "abc";
        System.out.println(new Anagrams().findAnagrams(s, t));
    }
}
