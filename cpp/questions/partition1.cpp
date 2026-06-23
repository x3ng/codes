#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> ans;        
        int ss = s.size();
        std::function<bool(int, int)> ir = [&](int l, int r) -> bool {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };
        std::vector<std::string> tmp;
        std::function<void(int)> bs = [&](int p) -> void {
            if (p == ss) {
                ans.emplace_back(tmp);
                return;
            }
            int l = p;
            for (int r=l; r<ss; ++r) {
                if (ir(l, r)) {
                    tmp.emplace_back(s.substr(l, r-l+1));
                    bs(r+1);
                    tmp.pop_back();
                }
            }
        };
        bs(0);
        return ans;
    }
};
