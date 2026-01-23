class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        std::set<std::pair<long long, int>> sp;
        std::set<int> rp;
        int dec = 0;
        for (int p=0; p<n-1; p++) {
           sp.emplace(nums[p]+nums[p+1], p);
           if (nums[p] > nums[p+1]) {
               dec++;
           };
           rp.insert(p);
        };
        rp.insert(n-1);
        std::vector<long long> st(nums.begin(), nums.end());
        int ans = 0;
        while (dec) {
            ans++;
            auto [s, p] = *sp.begin();
            sp.erase(sp.begin());
            auto pr = rp.lower_bound(p);
            auto pnp = next(pr);
            int pn = *pnp;
            dec -= st[p] > st[pn];
            if (pr != rp.begin()) {
                auto ppp = prev(pr);
                int pp = *ppp;
                dec -= st[pp] > st[p];
                dec += st[pp] > s;
                sp.erase({st[pp]+st[p], pp});
                sp.emplace(st[pp]+s, pp);
            }
            auto pnnp = next(pnp);
            if (pnnp != rp.end()) {
                int pnn = *pnnp;
                dec -= st[pn] > st[pnn];
                dec += s > st[pnn];
                sp.erase({st[pn]+st[pnn], pn});
                sp.emplace(s+st[pnn], p);
            }
            st[p] = s;
            rp.erase(pnp);
        };
        return ans;
    }
};
