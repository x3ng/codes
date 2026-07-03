#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        std::string ans = "";
        int p = 0;
        while (p < s.size()) {
            if (s[p]>='a' && s[p]<='z') {
                ans.push_back(s[p]);
                ++p;
            } else {
                int rt = 0;
                while (s[p] != '[') {
                    rt *= 10;
                    rt += s[p]-'0';
                    ++p;
                }
                int sp = ++p;
                int lmr = 1;
                while (lmr) {
                    if (s[p] == '[') {
                        lmr += 1;
                    } else if (s[p] == ']') {
                        lmr -= 1;
                    }
                    ++p;
                }
                std::string ss = decodeString(s.substr(sp, p-1-sp));
                while (rt--) {
                    ans.append(ss);
                }
            }
        }
        return ans;
    }
};
