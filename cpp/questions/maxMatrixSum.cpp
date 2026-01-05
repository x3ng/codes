class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn = INT_MAX;
        long long ans = 0;
        int neg_cnt = 0;
        for (auto& row : matrix) {
            for (auto& num : row) {
                if (num <= 0) {
                    ans += -num;
                    mn = std::min(mn, -num);
                    neg_cnt += 1;
                } else {
                    ans += num;
                    mn = std::min(mn, num);
                }
            }
        }
        if (neg_cnt%2 == 0) {
            return ans;
        }
        return ans-mn*2;
    }
};
