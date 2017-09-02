class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length - 1; i++) {
            sb.append(reverse(words[i])).append(" ");
        }
        return sb.append(reverse(words[words.length-1])).toString();
    }

    public String reverse(String s) {
        StringBuilder rs = new StringBuilder();
        for (int i = s.length()-1; i >= 0; i--) {
            rs.append(s.charAt(i));
        }
        return rs.toString();
    }
}
