import java.util.*;

public class Isomorphic {
    public boolean isIsomorphic(String s, String t) {
        int[] ds = string2Digit(s);
        int[] dt = string2Digit(t);

        if (!Arrays.equals(ds, dt)) {
            return false;
        }
        return true;
    }

    public int[] string2Digit(String str) {
        int[] ds = new int[str.length()];
        int count = 0;
        Map<Character, Integer> index = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (!index.containsKey(c)) {
                index.put(c, count++);
            }
            ds[i] = index.get(c);
        }
        return ds;
    }

    public boolean isIsomorphic2(String s, String t) {
        int[] m1 = new int[256];
        int[] m2 = new int[256];
        for (int i = 0; i < s.length(); i++) {
            if (m1[s.charAt(i)] != m2[t.charAt(i)]) {
                return false;
            }
            m1[s.charAt(i)] = i + 1;
            m2[t.charAt(i)] = i + 1;
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "paper";
        String t = "title";
        int[] a = new int[]{1,2,3};
        int[] b = new int[]{1,2,3};
        // System.out.println(!a.equals(b));
        System.out.println(new Isomorphic().isIsomorphic(s, t));
    }
}
