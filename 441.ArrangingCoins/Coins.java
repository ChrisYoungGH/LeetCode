class Solution {
    public int arrangeCoins(int n) {
        int ans = (int)(Math.sqrt(n) * Math.sqrt(2));
        return (int)((long)ans * (long)(ans + 1) / 2) <= n ? ans : ans - 1;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().arrangeCoins(1804289383));
    }
}
