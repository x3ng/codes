#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0; 
        std::unordered_map<int, int> hm;
        int ps = 0;
        hm[ps]++;
        for (int i=0; i<n; ++i) {
            ps += nums[i];
            ans += hm[ps-k];
            hm[ps]++;
        }
        return ans;
    }
};
