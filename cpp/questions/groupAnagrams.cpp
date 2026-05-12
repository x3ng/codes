#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hm;
        for (auto& s: strs) {
            std::string k = s;
            std::sort(k.begin(), k.end());
            hm[k].push_back(s);
        }
        std::vector<std::vector<std::string>> ans;
        for (const auto& p: hm) {
            ans.push_back(std::move(p.second));
        }
        return ans;
    }
};
