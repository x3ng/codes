#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 1;
        while (p<n && nums[p]>nums[p-1]) {
            p++;
        }
        if (p==1 || p==n) {
            return false;
        }
        while (p<n && nums[p]<nums[p-1]) {
            p++;
        }
        if (p == n) {
            return false;
        }
        while (p<n && nums[p]>nums[p-1]) {
            p++;
        }
        return p==n;
    }
};
