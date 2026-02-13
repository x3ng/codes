class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.size();

        for (int p=0; p<n;) {
            int sp = p;
            for (p++; p<n && s[p]==s[p-1]; p++);
            ans = std::max(ans, p-sp);
        }

        auto two = [&](char x, char y) -> void {
            for (int p=0; p<n; p++) {
                std::unordered_map<int, int> dp{{0, p-1}};
                int d = 0;
                for (; p<n && (s[p]==x || s[p]==y); p++) {
                    d += s[p]==x ? 1 : -1;
                    if (dp.find(d) != dp.end()) {
                        ans = std::max(ans, p-dp[d]);
                    } else {
                        dp[d] = p;
                    }
                }
            }
        };
        two('a', 'b');
        two('a', 'c');
        two('b', 'c');
        
        int cnt[3]{};
        std::unordered_map<long long, int> ep{{static_cast<long long>(n) << 32 | n, -1}};
        for (int p=0; p<n; p++) {
            cnt[s[p]-'a']++;
            long long ec = static_cast<long long>(cnt[0]-cnt[1]+n) << 32 | (cnt[1]-cnt[2]+n);
            if (ep.find(ec) != ep.end()) {
                ans = std::max(ans, p-ep[ec]);
            } else {
                ep[ec] = p;
            }
        }

        return ans;
    }
};
