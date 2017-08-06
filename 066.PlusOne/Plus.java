public class Plus {
    public int[] plusOne(int[] digits) {
        int up = 1;
        for (int i = digits.length-1; i >= 0; i--) {
            int val = digits[i] + up;
            digits[i] = val % 10;
            up = val / 10;
        }

        if (up > 0) {
            int[] newDigits = new int[digits.length+1];
            newDigits[0] = up;
            for (int i = 0; i < digits.length; i++) {
                newDigits[i+1] = digits[i];
            }
            return newDigits;
        }

        return digits;
    }
}
