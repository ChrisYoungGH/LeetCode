class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sumVal = 0;
        for (int i = 0; i < k; i++) {
            sumVal += nums[i];
        }
        int maxSum = sumVal;
        for (int i = 0; i < int(nums.size()) - k; i++) {
            sumVal += -nums[i] + nums[i+k];
            maxSum = max(maxSum, sumVal);
        }

        return (double)maxSum / k;
    }
};
