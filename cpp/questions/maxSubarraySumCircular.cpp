class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ns = nums.size();
        int b = nums[0];
        int bp = 0;
        int s = nums[0];
        int sp = 0;
        int sum = 0;
        for (const auto& n: nums) {
            bp = std::max(bp+n, n);
            b = std::max(bp, b);
            sp = std::min(sp+n, n);
            s = std::min(sp, s);
            sum += n;
        }
        int rs = sum - s;
        if (b < 0) {
            return b;
        } else {
            return b > rs ? b : rs;
        }
    }
};
