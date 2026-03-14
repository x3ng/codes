#include <string>
#include <array>

using namespace std;

class Solution {
private:
    std::array<char, 3> ele = {'a', 'b', 'c'};
public:
    string getHappyString(int n, int k) {
        int hsc = 3 << (n - 1);
        if (hsc < k) {
            return "";
        }
        --k;
        std::string ans(n, '\0');
        hsc /= 3;
        int pp = k / hsc;
        ans[0] = ele[pp];
        k %= hsc;
        for (int p=1; p<n; ++p) {
            hsc /= 2;
            int cp = k / hsc;
            cp = cp < pp ? cp : cp+1;
            ans[p] = ele[cp];
            k %= hsc;
            pp = cp;
        }
        return ans;
    }
};
