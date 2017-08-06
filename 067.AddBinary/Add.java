public class Add {
    public String addBinary(String a, String b) {
        int ia = a.length()-1, ib = b.length()-1;
        int carry = 0;
        StringBuilder sb = new StringBuilder();
        while (ia >= 0 || ib >= 0 || carry >0) {
            int va = 0, vb = 0;
            if (ia >= 0) {
                va = a.charAt(ia--) - '0';
            }
            if (ib >= 0) {
                vb = b.charAt(ib--) - '0';
            }
            int sum = va + vb + carry;

            sb.append(sum % 2);
            carry = sum / 2;
        }

        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println(new Add().addBinary("11", "1"));
    }
}
