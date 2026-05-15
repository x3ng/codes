#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ps = p.size();
        int l = 0;
        int r = 0;
        std::vector<int> ans; 
        int cc[26] = {0};
        for (const auto c: p) {
            cc[c-'a']++;
        }
        while (r < s.size()) {
            cc[s[r]-'a']--;
            while (cc[s[r]-'a'] < 0) {
                cc[s[l++]-'a']++;
            }
            if (++r-l == ps) {
                ans.push_back(l);
            }
        }
        return ans;
    }
};
