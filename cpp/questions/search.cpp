#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ns = nums.size();
        int nev = nums[ns-1];
        if (target == nev) {
            return ns-1;
        }
        int l = 0;
        int r = ns - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int mv = nums[m];
            if (mv == target) {
                return m;
            } else if (target > nev) {
                if (nums[m]<nev || nums[m]>target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (target < nev) {
                if (nums[m]>nev || nums[m]<target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return nums[l]==target ? l : -1;
    }
};
