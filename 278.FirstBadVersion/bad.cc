// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            // int mid = (left + right) / 2;       // 溢出
            int mid = left + (right - left) / 2;
            bool check = isBadVersion(mid);
            if (check) {
                if (mid == 1 || !isBadVersion(mid-1)) {
                    return mid;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                left = mid + 1;
            }
        }
        return 0;
    }
};
