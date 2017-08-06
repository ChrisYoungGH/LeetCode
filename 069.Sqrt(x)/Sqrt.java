public class Sqrt {
    // 要用长整型避免溢出
    public int mySqrt(int x) {
        long low = 0, high = x;
        long square = 0, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            square = mid * mid;
            if (square == x) {
                return (int)mid;
            }
            if (square > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)(square <= x ? mid : mid-1);
    }

    public static void main(String[] args) {
        System.out.println(new Sqrt().mySqrt(2147395599));
    }
}
