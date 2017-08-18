class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> counts = new HashMap<>();
        for (int i = 0; i < list1.length; i++) {
            counts.put(list1[i], i);
        }

        List<String> ans = new ArrayList<>();
        int minIndex = list1.length + list2.length;
        for (int i = 0; i < list2.length; i++) {
            String v = list2[i];
            if (!counts.containsKey(v)) {
                continue;
            }
            int sumIndex = counts.get(v) + i;
            if (sumIndex < minIndex) {
                minIndex = sumIndex;
                ans = new ArrayList<String>();
                ans.add(v);
            }
            else if (sumIndex == minIndex) {
                ans.add(v);
            }
        }

        return ans.toArray(new String[ans.size()]);
    }
}
