class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int pre = 0;
        while (n!=0 && !(n&1)) {
            n >>= 1;
            pre++;
        }
        for (int p=pre+1; n!=0; p++) {
            n >>= 1;
            if (n & 1) {
                ans = std::max(p-pre, ans);
                pre = p;
            }
        }
        return ans;
    }
};
