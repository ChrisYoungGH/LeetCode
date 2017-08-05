public class Count {
    public String countAndSay(int n) {
        if (n < 1) {
            return "";
        }
        String curr = "1";
        for (int i = 0; i < n - 1; i++) {
            curr = read(curr);
        }

        return curr;
    }

    public String read(String str) {
        if (str == null || str.isEmpty()) {
            return "";
        }
        char digit = str.charAt(0);
        int count = 1;
        StringBuilder res = new StringBuilder();
        for (int i = 1; i < str.length(); i++) {
            char curr = str.charAt(i);
            if (curr == digit) {
                count++;
            }
            else {
                res.append(count).append(digit);
                digit = curr;
                count = 1;
            }
        }
        res.append(count).append(digit);
        return res.toString();
    }

    public static void main(String[] args) {
        System.out.println(new Count().countAndSay(4));
    }
}
