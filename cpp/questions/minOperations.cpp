class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        std::set<int> nv[2];
        for (int s=0; s<2; ++s) {
            for (int p=s; p<=n; p+=2) {
                nv[s%2].insert(p);
            }
            nv[s%2].insert(n+1);
        }
        int c0 = ranges::count(s, '0');
        std::vector<int> step = {c0};
        for (int ans=0; !step.empty(); ++ans) {
            std::vector<int> tmp;
            for (const auto& e: step) {
                if (e == 0) {
                    return ans;
                }
                int tmpc = e + k;
                int r = tmpc - 2 * std::max(0, k-n+e);
                int l = tmpc - 2 * std::min(k, e);
                auto& st = nv[tmpc%2];
                for (auto it = st.lower_bound(l); *it<=r; it=st.erase(it)) {
                    tmp.push_back(*it);
                }
            }
            step = std::move(tmp);
        }
        return -1;
    }
};
