class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& num: nums) {
            if (num == 2) {
                num = -1;
            } else {
                int tmp = ~num;
                num ^= (tmp&-tmp) >> 1;
            }
        }
        return nums;
    }
};
