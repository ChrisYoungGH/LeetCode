public class Distance {
    public int hammingDistance(int x, int y) {
        int z = x ^ y;
        int d = 0;
        while (z != 0) {
            d += z % 2;
            z /= 2;
        }
        return d;
    }

    public static void main(String[] args) {
        System.out.println(new Distance().hammingDistance(1,4));
    }
}
