#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static constexpr const char* kc[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int ds = digits.size();
        std::string tmp;
        tmp.resize(ds);
        std::vector<std::string> ans;
        std::function<void(int)> bs = [&](int p) -> void {
            if (p == ds) {
                ans.push_back(tmp);
                return;
            }
            for (const auto c: std::string(kc[digits[p]-'2'])) {
                tmp[p] = c;
                bs(p+1);
            }
        };
        bs(0);
        return ans;
    }
};
