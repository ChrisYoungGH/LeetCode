class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (pair<int, int> p : points) {
            map<int, int> m;
            for (pair<int, int> q : points) {
                int x = p.first - q.first;
                int y = p.second - q.second;
                int dist = x * x + y * y;
                m[dist]++;
            }

            for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
                ans += it->second * (it->second - 1);
            }
        }

        return ans;
    }
};
