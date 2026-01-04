class Solution {
private:
    int fourDivisorsSum(const int& num) {
        if (num < 6) {
            return 0;
        }
        int sqrt_num = static_cast<int>(sqrt(num));
        if (num == sqrt_num * sqrt_num) {
            return 0;
        }
        int sum = 1+num;
        for (int n=2; n<=sqrt_num; n++) {
            if (num % n == 0) {
                if (sum == num+1) {
                    sum += n+num/n;
                } else {
                    return 0;
                }
            }
        }
        return sum==1+num ? 0 : sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        std::map<int, int> sm;
        for (const int& num : nums) {
            auto it = sm.find(num);
            if (it != sm.end()) {
                ans += sm[num];
            } else {
                sm[num] = fourDivisorsSum(num);
                ans += sm[num];
            }
        }
        return ans;
    }
};
