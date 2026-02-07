#include <vector>
#include <climits>

using namesapce std;

class Solution {
public:
    int minimumDeletions(string s) {
        int del = 0;
        for (auto c: s) {
            del += 'b' - c;
        }
        int ans = del;
        for (auto c: s) {
            del += (c-'a') * 2 - 1;
            ans = std::min(ans, del);
        }
        return ans;
    }
};
