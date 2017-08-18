class Solution {
    public String[] findWords(String[] words) {
        String[] keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        Map<Character, Integer> keyMap = new HashMap<>();
        for (int i = 0; i < keyboard.length; i++) {
            for (char c : keyboard[i].toCharArray()) {
                keyMap.put(c, i);
            }
        }

        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (word.length() == 0) {
                continue;
            }
            String lowerWord = word.toLowerCase();
            int flag = keyMap.get(lowerWord.charAt(0));

            for (char c : lowerWord.toCharArray()) {
                if (keyMap.get(c) != flag) {
                    flag = -1;
                    break;
                }
            }

            if (flag != -1) {
                result.add(word);
            }
        }

        return result.toArray(new String[result.size()]);
    }
}
