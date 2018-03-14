import java.util.*;
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer, Integer> unique = new HashMap<>();
        for (int n : nums1) {
            unique.put(n, 1);
        }
        List<Integer> ans = new ArrayList<>();
        for (int n : nums2) {
            if (unique.containsKey(n) && unique.get(n) == 1) {
                ans.add(n);
                unique.put(n, 0);
            }
        }

        int[] inter = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            inter[i] = ans.get(i);
        }

        return inter;
    }
}
