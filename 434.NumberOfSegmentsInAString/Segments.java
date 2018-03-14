class Solution {
    public int countSegments(String s) {
        int count = 0;
        int flag = 0;
        for (char c : s.toCharArray()) {
            if (!Character.isSpace(c)) {
                flag = 1;
            }
            else {
                if (flag == 1) {
                    count++;
                }
                flag = 0;
            }
        }
        return count + (flag == 1 ? 1 : 0);
    }
}
