class Solution {
    public boolean checkRecord(String s) {
        int countA = 0, countL = 0;
        for (char c : s.toCharArray()) {
            if (c == 'L') {
                countL++;
            }
            else {
                countL = 0;
                if (c == 'A') {
                    countA++;
                }
            }

            if (countA > 1 || countL > 2) {
                return false;
            }
        }

        return true;
    }
}
