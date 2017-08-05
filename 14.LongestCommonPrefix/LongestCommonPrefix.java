import java.lang.Math;

public class LongestCommonPrefix {

    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }

        if (strs.length == 1) {
            return strs[0];
        }

        int minLen = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            minLen = strs[i].length() < minLen ? strs[i].length() : minLen;
        }

        String repStr = strs[0];
        int longestIndex = 0;
        boolean flag = true;

        for (int i = 0; i < minLen; i++) {
            char c = repStr.charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].charAt(i) != c) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            longestIndex++;
        }

        return longestIndex > 0 ? repStr.substring(0, longestIndex) : "";
    }

    public static void main(String[] args) {
        String[] strs = new String[]{"hello", "hella", "helly", "helllllllllll"};
        String res = new LongestCommonPrefix().longestCommonPrefix(strs);
        System.out.println(res);
    }
}
