#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        std::sort(nums.begin()+1, nums.end());
        return reduce(nums.begin(), nums.begin()+3, 0);
    }
};
