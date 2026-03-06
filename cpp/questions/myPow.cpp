class Solution {
public:
    double myPow(double x, int n) {
        long long pn = n;
        if (n < 0) {
            x = 1 / x;
            pn = -pn;
        }
        double ans = 1;
        while (pn > 0) {
            bool bv = pn & 1;
            ans *= bv ? x : 1;
            x *= x;
            pn >>= 1;
        }
        return ans;
    }
};
