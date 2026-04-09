#include <vector>
#include <cmath>
#include <numeric>
#include <functional>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1e9 + 7;

    long long pow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n % 2) {
                res = res * x % MOD;
            }
            n >>= 1;
            x = x * x % MOD;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qs = std::sqrt(queries.size());
        std::vector<std::vector<int>> tmp(qs);
        for (const auto& q: queries) {
            const auto& l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            if (k >= qs) {
                for (int p=l; p<=r; p+=k) {
                    nums[p] = nums[p] * v % MOD;
                }
            } else {
                if (tmp[k].empty()) {
                    tmp[k].resize(n+k, 1);
                }
                tmp[k][l] = tmp[k][l] * v % MOD;
                int e = k + r - (r - l) % k;
                tmp[k][e] = tmp[k][e] * pow(v, MOD-2) % MOD;
            }
        }
        for (int k=0; k<tmp.size(); ++k) {
            const auto& t = tmp[k];
            if (t.empty()) {
                continue;
            } else {
                for (int s=0; s<k; ++s) {
                    long long mul = 1;
                    for (int p=s; p<n; p+=k) {
                        mul = mul * t[p] % MOD;
                        nums[p] = nums[p] * mul % MOD;
                    }
                }
            }
        }
        return std::reduce(nums.begin(), nums.end(), 0, bit_xor());
    }
};
