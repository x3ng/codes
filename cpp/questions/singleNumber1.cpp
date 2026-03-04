#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int p=0; p<32; ++p) {
            int cnt = 0;
            for (const auto& num: nums) {
                cnt += (num >> p) & 1;
            }
            ans |= (cnt % 3) << p;
        }
        return ans;
    }
};
