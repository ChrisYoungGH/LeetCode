import java.util.*;
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer, Integer> unique = new HashMap<>();
        for (int n : nums1) {
            if (!unique.containsKey(n)) {
                unique.put(n, 0);
            }
            unique.put(n, unique.get(n)+1);
        }
        List<Integer> ans = new ArrayList<>();
        for (int n : nums2) {
            if (unique.containsKey(n) && unique.get(n) > 0) {
                ans.add(n);
                unique.put(n, unique.get(n)-1);
            }
        }

        int[] inter = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            inter[i] = ans.get(i);
        }

        return inter;
    }
}
