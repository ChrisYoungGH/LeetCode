class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int minRadius = 0;
        for (int h : houses) {
            minRadius = max(minRadius, distance(h, heaters));
        }

        return minRadius;
    }

    int distance(int h, vector<int>& heaters) {
        int low = 0, high = int(heaters.size()) - 1;
        if (h < heaters[low]) {
            return heaters[low] - h;
        }
        if (h > heaters[high]) {
            return h - heaters[high];
        }

        while (true) {
            int mid = low + (high - low) / 2;
            if (heaters[mid] == h) {
                return 0;
            }
            if (high - low <= 1) {
                return min(h - heaters[low], heaters[high] - h);
            }

            if (h > heaters[mid]) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
    }
};
