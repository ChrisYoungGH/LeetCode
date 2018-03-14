class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> candySet = new HashSet<>();
        for (int c : candies) {
            candySet.add(c);
        }
        return Math.min(candies.length / 2, candySet.size());
    }
}
