public class Reverse {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;

        for (int i = 0; i < 32; i++) {
            res += n & 1;
            n >>>= 1;   // unsigned shift
            if (i < 31) {
                res <<= 1;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        System.out.println(new Reverse().reverseBits(2147483648));
    }
}
