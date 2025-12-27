class Solution {
private:
    int findbt(const std::vector<std::vector<int>>& events, int n, int t) {
        int s = 0;
        int e = n-1;
        int m = (s+e)/2;
        if (t >= events[e][0]) {
            return -1;
        }
        while (1) {
            m = (s+e)/2;
            if (s == m) {
                return e;
            } else if (events[m][0] <= t) {
                s = m;
            } else {
                e = m;
            }
        }
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        std::vector<int> mv(n);
        std::sort(events.begin(), events.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        mv[n-1] = events[n-1][2];
        for (int p=n-2; p>=0; p--) {
            mv[p] = std::max(mv[p+1], events[p][2]);
        }
        int ce = 0;
        int ans = 0;
        int fr = 0;
        for (int p=0; p<n; p++) {
            ce = events[p][1];
            fr = findbt(events, n, ce);
            if (fr >= 0) {
                ans = std::max(ans, events[p][2]+mv[fr]);
            } else {
                ans = std::max(ans, events[p][2]);
            }
        }
        return ans;
    }
};
