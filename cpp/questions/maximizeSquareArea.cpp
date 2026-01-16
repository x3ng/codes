class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto addBorderSort = [](std::vector<int>& fences, int b) -> void {
            fences.push_back(1);
            fences.push_back(b);
            ranges::sort(fences);
        };
        addBorderSort(hFences, m);
        addBorderSort(vFences, n);
        std::unordered_map<int, int> hvm;
        int maxb = 0;
        for (int& h: hFences) {
            for (int& v: vFences) {
                int curhv = h - v;
                if (hvm.count(curhv)) {
                    maxb = std::max(maxb, h-hvm[curhv]);
                } else {
                    hvm[curhv] = h;
                }
            }
        }
        return maxb==0 ? -1 : static_cast<long long>(maxb) * maxb % MOD;
    }
};
