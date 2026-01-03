class Solution {
public:
    int numOfWays(int n) {
        constexpr int MOD = 1'000'000'007;
        std::vector<int> f(n+1);
        f[0] = 3;
        f[1] = 12;
        for (int r=2; r<=n; r++) {
            f[r] = (f[r-1] * 5LL - f[r-2] * 2LL) % MOD;
        }
        return (f[n]+MOD) % MOD;
    }
};
