public class StrStr {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) {
            return -1;
        }

        if (haystack == "" && needle == "") {
            return 0;
        }

        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            if (haystack.substring(i, i+needle.length()).equals(needle)) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        String haystack = "abb";
        String needle = "abaaa";
        System.out.println(new StrStr().strStr(haystack, needle));
    }
}
