class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            int l = i + 1, h = nums.length - 1;
            int sum = -nums[i];
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            while (l < h) {
                if (nums[l] + nums[h] == sum) {
                    ans.add(Arrays.asList(nums[i], nums[l], nums[h]));
                    while (l < h && nums[l+1] == nums[l]) l++;
                    l++;
                    while (l < h && nums[h-1] == nums[h]) h--;
                    h--;
                }
                else if (nums[l] + nums[h] < sum) l++;
                else h--;
            }

        }

        return ans;
    }
}
