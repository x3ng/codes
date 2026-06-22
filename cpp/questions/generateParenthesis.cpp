#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans;        
        std::string tmp(n*2, '0');
        std::function<void(int, int)> bs = [&](int p, int l) -> void {
            if (l == n) {
                while (p < n*2) {
                    tmp[p++] = ')';
                }
                ans.emplace_back(tmp);
                return;
            }
            if (p < l*2) {
                tmp[p] = ')';
                bs(p+1, l);
            }
            tmp[p] = '(';
            bs(p+1, l+1);
        };
        bs(0, 0);
        return ans;
    }
};
