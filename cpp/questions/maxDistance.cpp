#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int p2 = nums2.size() - 1;
        int p1 = std::min(nums1.size(), nums2.size()) - 1;
        for (; p1>=0; --p1) {
            const int v1 = nums1[p1];
            while (p2>p1 && nums2[p2]<nums1[p1]) {
                --p2;
            }
            if (nums2[p2] >= nums1[p1]) {
                ans = std::max(ans, p2-p1);
            }
        }
        return ans;
    }
};
