class Solution {
    public boolean isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        if (num < 2) {
            return true;
        }
        int root = 2;
        while (root <= num / root) {
            if (root * root == num) {
                return true;
            }
            root++;
        }
        return false;
    }
}
