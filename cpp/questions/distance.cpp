#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> arr(n, 0);
        std::unordered_map<int, long long> hs;
        std::unordered_map<int, int> hi;
        for (int p=0; p<n; ++p) {
            const int k = nums[p];
            long long& ps = hs[k];
            int& ci = hi[k];
            arr[p] += static_cast<long long>(p) * ci - ps;
            ++ci;
            ps += p;
        }

        hs.clear();
        hi.clear();

        for (int p=n-1; p>=0; --p) {
            const int k = nums[p];
            long long& ts = hs[k];
            int& ci = hi[k];
            arr[p] += ts - static_cast<long long>(p) * ci;
            ++ci;
            ts += p;
        }
        return arr;
    }
};
