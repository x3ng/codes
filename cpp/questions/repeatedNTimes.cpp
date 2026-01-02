class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::map<int, int> numcnt;
        int len = nums.size() / 2;
        for (int& num : nums) {
            if (++numcnt[num] == len) {
                return num;
            }
        }
        return -1;
    }
};
