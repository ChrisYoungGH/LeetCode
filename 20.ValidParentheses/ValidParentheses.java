import java.util.*;

public class ValidParentheses {
    // 方法1
    public boolean isValid(String s) {
        if (s == null || s.length() % 2 != 0) {
            return false;
        }

        String[] seq = s.split("");

        List<String> left = new ArrayList<String>() {
            {
                add("(");
                add("[");
                add("{");
            }
        };

        Map<String, String> right = new HashMap<String, String>() {
            {
                put(")", "(");
                put("]", "[");
                put("}", "{");
            }
        };

        Map<String, Integer> count = new HashMap<String, Integer>() {
            {
                put("(", 0);
                put(")", 0);
                put("[", 0);
                put("]", 0);
                put("{", 0);
                put("}", 0);
            }
        };

        Stack<String> stack = new Stack<String>();
        for (String p : seq) {
            // 统计括号数
            count.put(p, count.get(p) + 1);
            // 左括号入栈
            if (left.contains(p)) {
                stack.push(p);
            }
            // 右括号匹配弹出栈顶
            else {
                if (!stack.empty() && right.get(p).equals(stack.peek())) {
                    stack.pop();
                }
            }
        }

        // 计算左右括号数目是否匹配
        if ((count.get("(") - count.get(")") != 0)
                || (count.get("[") - count.get("]") != 0)
                || (count.get("{") - count.get("}") != 0)) {
            return false;
        }

        if (stack.empty()) {
            return true;
        }

        return false;
    }

    // 方法2：每个右括号都要与当前栈顶匹配，否则为非法
    public boolean isValidOpt(String s) {
        if (s == null) {
            return false;
        }

        Map<Character, Character> par = new HashMap<Character, Character>() {
            {
                put('(', ')');
                put('[', ']');
                put('{', '}');
            }
        };

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (par.keySet().contains(c)) {
                stack.push(c);
            }
            else if (par.values().contains(c)) {
                if (!stack.empty() && par.get(stack.peek()) == c) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return stack.empty();
    }

    // 方法2简洁版
    public boolean isValidOptOpt(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(')');
            }
            else if (c == '[') {
                stack.push(']');
            }
            else if (c == '{') {
                stack.push('}');
            }
            else if (stack.isEmpty() || stack.pop() != c) {
                return false;
            }
        }
        return stack.isEmpty();
    }


    public static void main(String[] args) {
        String s = "()";
        ValidParentheses v = new ValidParentheses();
        System.out.println(v.isValidOptOpt(s));
    }
}
