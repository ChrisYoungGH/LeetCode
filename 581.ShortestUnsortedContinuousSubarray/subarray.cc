class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());

        int n = int(nums.size());
        int begin = 0, end = n-1;

        while (begin < end) {
            if (nums[begin] == sortedNums[begin]) {
                begin++;
            }
            else {
                break;
            }
        }

        while (end > begin) {
            if (nums[end] == sortedNums[end]) {
                end--;
            }
            else {
                break;
            }
        }

        int len = end - begin + 1;
        return len != 1 ? len : 0;
    }


    int findUnsortedSubarray2(vector<int>& nums) {
        int n = int(nums.size());
        int begin = -1, end = -2;
        int maxVal = nums[0], minVal = nums[n-1];

        for (int i = 1; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[n-i-1]);

            end = nums[i] < maxVal ? i : end;
            begin = nums[n-i-1] > minVal ? n-i-1 : begin;
        }

        return end - begin + 1;
    }
};
