#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hm; 
        for (int i=0; i<nums.size(); ++i) {
            const int n = nums[i];
            auto it = hm.find(target-n);
            if (it != hm.end()) {
                return {i, it->second};
            }
            hm[n] = i;
        }
        return {};
    }
};
