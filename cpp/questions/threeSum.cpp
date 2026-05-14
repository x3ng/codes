#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        for (int i=0; i<n-2; ++i) {
            if (nums[i]+nums[i+1]+nums[i+2] > 0) {
                break;
            }
            if ((i>0 && nums[i]==nums[i-1]) || nums[i]+nums[n-2]+nums[n-1]<0) {
                continue;
            }
            int t = nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int s = t + nums[l] + nums[r];
                if (s > 0) {
                    --r;
                } else if (s < 0) {
                    ++l;
                } else {
                    ans.push_back({t, nums[l], nums[r]});
                    ++l;
                    while (l<r && nums[l-1]==nums[l]) {
                        ++l;
                    }
                    --r;
                    while (l<r && nums[r]==nums[r+1]) {
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};
