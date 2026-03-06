class Solution {
public:
    int mySqrt(int x) {
        if (x < 4) {
            return x ? 1 : 0;
        }
        int l = 0;
        int r = x;
        while (r-l > 1) {
            int m = (l + r) / 2;
            long long tmp = static_cast<long long>(m) * m;
            if (x == tmp) {
                return m;
            } else if (x > tmp) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};
