public class LastWord {

    // 方法1：直接调用split方法
    public int lengthOfLastWord(String s) {
        String[] words = s.split(" ");
        return (words == null || words.length == 0) ? 0 : words[words.length-1].length();
    }

    // 方法2：从后往前扫到第一个非空格字符，开始计数，直到遇到空格
    public int lengthOfLastWord2(String s) {
        int i = s.length() - 1;
        while (i >= 0) {
            if (s.charAt(i) != ' ') {
                break;
            }
            i--;
        }

        int count = 0;
        while (i >= 0 && s.charAt(i) != ' ') {
            count++;
            i--;
        }

        return count;
    }


    public static void main(String[] args) {
        System.out.println(new LastWord().lengthOfLastWord2("   "));
    }
}
