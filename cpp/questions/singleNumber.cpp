#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int p=1; p<nums.size(); ++p) {
            ans ^= nums[p];
        }
        return ans;
    }
};
