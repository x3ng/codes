#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        std::vector<std::vector<int>> way(26, std::vector<int>(26, INT_MAX));
        for (int p=0; p<original.size(); p++) {
            int r = original[p] - 'a';
            int c = changed[p] - 'a';
            way[r][c] = std::min(way[r][c], cost[p]);
        }
        for (int p=0; p<26; p++) {
            way[p][p] = 0;
        }
        for (int f=0; f<26; f++) {
            for (int r=0; r<26; r++) {
                for (int c=0; c<26; c++) {
                    long long jc = static_cast<long long>(way[r][f]) + static_cast<long long>(way[f][c]);
                    if (jc > INT_MAX) {
                        continue;
                    }
                    way[r][c] = std::min(way[r][c], static_cast<int>(jc));
                }
            }
        }
        long long ans = 0;
        for (int p=0; p<source.size(); p++) {
            if (source[p] != target[p]) {
                int cc = way[source[p]-'a'][target[p]-'a'];
                if (cc == INT_MAX) {
                    return -1;
                }
                ans += cc;
            }
        }
        return ans;
    }
};
