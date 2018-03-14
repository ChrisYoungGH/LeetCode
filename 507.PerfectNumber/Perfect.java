class Solution {
    public boolean checkPerfectNumber(int num) {
        int sum = 1;
        int fac = 2;
        while (fac <= num / fac) {
            if (num % fac == 0) {
                sum += fac + num / fac;
            }
            fac++;
        }
        if (num > 1 && sum == num) {
            return true;
        }
        return false;
    }
}
