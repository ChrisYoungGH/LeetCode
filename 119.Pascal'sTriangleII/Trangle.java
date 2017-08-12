import java.util.*;

public class Trangle {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        ans.add(Integer.valueOf(1));
        for (int i = 1; i < rowIndex + 1; i++) {
            ans.add(Integer.valueOf(1));
            for (int j = i-1; j >= 1; j--) {
                ans.set(j, ans.get(j) + ans.get(j-1));
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            System.out.println(new Trangle().getRow(i));
        }
    }
}
