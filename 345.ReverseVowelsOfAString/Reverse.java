class Solution {
    public String reverseVowels(String s) {
        String vowelStr = "aeiouAEIOU";
        Set<Character> vowels = new HashSet<Character>();
        for (char c : vowelStr.toCharArray()) {
            vowels.add(c);
        }

        List<Integer> index = new ArrayList<>();
        char[] sCharArray = s.toCharArray();
        for (int i = 0; i < sCharArray.length; i++) {
            if (vowels.contains(sCharArray[i])) {
                index.add(i);
            }
        }

        for (int i = 0; i < index.size() / 2; i++) {
            int left = index.get(i);
            int right = index.get(index.size() - i - 1);
            char tmp = sCharArray[left];
            sCharArray[left] = sCharArray[right];
            sCharArray[right] = tmp;
        }

        return String.valueOf(sCharArray);
    }
}
