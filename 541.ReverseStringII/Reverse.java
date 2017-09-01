class Solution {
    public String reverseStr(String s, int k) {
        if (s == null) {
            return null;
        }

        int end = s.length() / (2*k) * (2*k);
        char[] charArray = s.toCharArray();

        for (int i = 0; i < end; i += 2*k) {
            for (int j = i; j < i + k; j++) {
                int index = i + k - j - 1;
                char tmp = charArray[j];
                charArray[j] = charArray[index];
                charArray[index] = tmp;
            }
        }

        int begin = end;
        end = s.length() - begin < k ? begin : s.length() + k;

        for (int j = begin; j < (end - begin) / 2 + begin; j++) {
            int index = (end - begin) / 2 + begin - j - 1;
            char tmp = charArray[j];
            charArray[j] = charArray[index];
            charArray[index] = tmp;
        }

        StringBuilder sb = new StringBuilder();
        for (char c : charArray) {
            sb.append(c);
        }

        return sb.toString();
    }
}
