import java.util.*;

public class Trangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        if (numRows <= 0) {
            return ans;
        }
        
        List<Integer> curr = new ArrayList<>();
        curr.add(Integer.valueOf(1));
        ans.add(curr);

        for (int i = 1; i < numRows; i++) {
            curr = new ArrayList<>();
            curr.add(Integer.valueOf(1));
            ans.add(curr);

            curr = ans.get(i);
            List<Integer> prev = ans.get(i-1);

            for (int j = 1; j < i; j++) {
                curr.add(prev.get(j) + prev.get(j-1));
            }

            curr.add(Integer.valueOf(1));
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(new Trangle().generate(5));
    }
}
