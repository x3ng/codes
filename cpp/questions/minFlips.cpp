#include <string>
#include <array>

using namespace std;

class Solution {
private:
    static constexpr std::array<char, 2> bc = {'0', '1'};
public:
    int minFlips(string s) {
        int ss = s.size();
        int cnt = 0;
        int ans = ss;
        for (int p=0; p<2*ss-1; ++p) {
            cnt += s[p%ss]==bc[p%2];
            int lb = p - ss +  1;
            if (lb < 0) {
                continue;
            }
            ans = std::min(ans, std::min(cnt, ss-cnt));
            cnt -= s[lb%ss]==bc[lb%2];
        }
        return ans;
    }
};
