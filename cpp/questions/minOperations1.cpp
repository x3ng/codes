#include <array>
#include <string>

using namespace std;

class Solution {
private:
    std::array<char, 2> tg = {'0', '1'};
public:
    int minOperations(string s) {
        int ss = s.size();
        int cnt = 0;
        for (int p=0; p<ss; ++p) {
            cnt += s[p]!=tg[p&1];
        }
        return std::min(cnt, ss-cnt);
    }
};
