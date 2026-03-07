#include <string>
#include <vector>
#include <ranges>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int ss = s.size();
        int ml = ranges::max(wordDict, {}, &std::string::size).size();
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        std::vector<bool> sf(ss+1, false);
        sf[0] = true;
        for (int r=1; r<=ss; ++r) {
            for (int l=r-1; l>=std::max(0, r-ml); --l) {
                if (sf[l] && words.contains(s.substr(l, r-l))) {
                    sf[r] = true;
                    break;
                }
            }
        }
        return sf[ss];

    }
};
