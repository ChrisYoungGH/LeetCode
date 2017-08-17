class Solution {
public:
    bool isHappy(int n) {
        set<int> nums;

        while (n > 1) {
            set<int>::iterator it = nums.find(n);
            if (it != nums.end()) {
                return false;
            }
            nums.insert(n);

            int tmp = n;
            int sum = 0;
            while (tmp > 0) {
                int d = tmp % 10;
                tmp /= 10;
                sum += d * d;
            }

            n = sum;
        }

        return true;
    }
};
