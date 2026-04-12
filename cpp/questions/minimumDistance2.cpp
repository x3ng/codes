#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution {
private:
    static constexpr int ir = 6;

    int dis(const int& s, const int& d) {
        return std::abs(s%ir-d%ir) + std::abs(s/ir-d/ir);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();
        std::vector<std::vector<int>> memo(n+1, std::vector<int>(n+1, -1));
        std::function<int(int, int, int)> dfs = [&](int p1, int p2, int np) -> int {
            if (p1==n-1 || p2==n-1) {
                memo[p1][p2] = 0;
                memo[p2][p1] = 0;
                return 0;
            }
            int& cc = memo[p1][p2];
            if (cc != -1) {
                return cc;
            }
            int cn = word[np] - 'A';
            int c1 = p1==n ? cn : word[p1]-'A';
            int c2 = p2==n ? cn : word[p2]-'A';

            int& m1 = memo[np][p2];
            int& m2 = memo[p1][np];
            if (m1 == -1) {
                m1 = dfs(np, p2, np+1);
            }
            cc = dis(c1, cn) + m1;
            if (m2 == -1) {
                m2 = dfs(p1, np, np+1);
            }
            cc = std::min(cc, dis(c2, cn)+m2);
            memo[p2][p1] = cc;
            return cc;
        };
        return dfs(n, n, 0);
    }
};
