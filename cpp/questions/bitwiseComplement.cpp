class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int tmp = n;
        int MOD = 1;
        while (tmp) {
            n ^= MOD;
            MOD <<= 1;
            tmp >>= 1;
        }
        return n;
    }
};
