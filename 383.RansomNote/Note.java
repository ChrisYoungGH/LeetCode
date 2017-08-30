class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> letterCount = new HashMap<>();
        for (char c : magazine.toCharArray()) {
            letterCount.put(c, letterCount.getOrDefault(c, 0) + 1);
        }

        for (char c : ransomNote.toCharArray()) {
            if (letterCount.getOrDefault(c, 0) <= 0) {
                return false;
            }
            letterCount.put(c, letterCount.getOrDefault(c, 0) - 1);
        }

        return true;
    }
}
