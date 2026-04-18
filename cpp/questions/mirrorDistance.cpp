#include <math.h>

class Solution {
public:
    int mirrorDistance(int n) {
        int tmp = n;
        int rn = 0;
        while (n && n%10 == 0) {
            n /= 10;
        }
        while (n) {
            rn = rn * 10 + n % 10;
            n /= 10;
        }
        return std::abs(rn - tmp);
    }
};
