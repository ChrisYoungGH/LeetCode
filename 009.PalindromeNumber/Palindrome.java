public class Palindrome {
    public boolean isPalindrome(int x) {
        String xStr = String.valueOf(x);
        for (int i = 0; i < xStr.length() / 2; i++) {
            if (xStr.charAt(i) != xStr.charAt(xStr.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int x = 123321;
        System.out.println(new Palindrome().isPalindrome(x));
    }
}
