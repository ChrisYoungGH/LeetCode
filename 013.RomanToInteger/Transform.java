import java.util.*;

public class Transform {
    public int romanToInt(String s) {
        Map<Character, Integer> dict = new HashMap<Character, Integer>() {
            {
                put('I', 1);
                put('V', 5);
                put('X', 10);
                put('L', 50);
                put('C', 100);
                put('D', 500);
                put('M', 1000);
            }
        };

        int sum = 0;
        for (int i = 0; i < s.length()-1; i++) {
            int curr = dict.get(s.charAt(i));
            int next = dict.get(s.charAt(i+1));
            if (curr < next) {
                sum -= curr;
            }
            else {
                sum += curr;
            }
        }

        return sum + dict.get(s.charAt(s.length()-1));
    }

    public static void main(String[] args) {
        System.out.println(new Transform().romanToInt("CMXCIX"));
    }
}
