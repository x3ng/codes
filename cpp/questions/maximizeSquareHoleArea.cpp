class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());
        auto getmc = [](std::vector<int>& Bars) -> int {
            int mc = 2;
            int cc = 2;
            int prev = Bars[0];
            int curr;
            for (int p=1; p<Bars.size(); p++) {
                curr = Bars[p];
                if (curr == prev+1) {
                    cc++;
                } else {
                    mc = std::max(mc, cc);
                    cc = 2;
                }
                prev = curr;
            }
            mc = std::max(mc, cc);
            return mc;
        };
        int mhc = getmc(hBars);
        int mvc = getmc(vBars);
        int mc = std::min(mhc, mvc);
        return mc * mc;
    }
};
