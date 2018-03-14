import java.util.*;

public class Pattern {
    public boolean wordPattern(String pattern, String str) {
        String[] strs = str.split(" ");
        if (pattern.length() != strs.length) {
            return false;
        }

        Map<String, Integer> indexMap = new HashMap<>();
        int count = 0;
        for (String s : strs) {
            if (!indexMap.containsKey(s)) {
                indexMap.put(s, count++);
            }
        }
        int[] indices = new int[strs.length];
        for (int i = 0; i < strs.length; i++) {
            indices[i] = indexMap.get(strs[i]);
        }

        Map<Character, Integer> digitMap = new HashMap<>();
        count = 0;
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            if (!digitMap.containsKey(c)) {
                digitMap.put(c, count++);
            }
            if (digitMap.get(c) != indices[i]) {
                return false;
            }
        }

        return true;
    }

    public boolean wordPatternOpt(String pattern, String str) {
        String[] strs = str.split(" ");
        if (strs.length != pattern.length()) {
            return false;
        }

        Map index = new HashMap();
        for (Integer i = 0; i < pattern.length(); i++) {
            if (index.put(pattern.charAt(i), i) != index.put(strs[i], i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String pattern = "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdd";
        String str = "s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s t t";
        System.out.println(new Pattern().wordPatternOpt(pattern, str));


    }
}
