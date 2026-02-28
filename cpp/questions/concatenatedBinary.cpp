class Solution {
private:
    static constexpr int MOD = 1'000'000'007;
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int cn=1; cn<=n; ++cn) {
            int cnc = std::bit_width(static_cast<uint32_t>(cn));
            ans = ((ans << cnc) | cn) % MOD;
        }
        return ans;
    }
};
