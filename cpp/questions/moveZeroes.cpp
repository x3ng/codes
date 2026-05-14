#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        int nz = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] != 0) {
                nums[nz++] = nums[i];
            }
        }
        for (; nz<n; ++nz) {
            nums[nz] = 0;
        }
    }
};
