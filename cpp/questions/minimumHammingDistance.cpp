#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    struct area {
        std::vector<int> ai;

        area(int n) {
            ai.resize(n);
            for (int i=0; i<n; ++i) {
                ai[i] = i;
            }
        }

        int getroot(int p) {
            if (ai[p] == p) {
                return p;
            } else {
                int tr = getroot(ai[p]);
                ai[p] = tr;
                return tr;
            }
        }

        void connect(int p0, int p1) {
            int r0 = getroot(p0);
            int r1 = getroot(p1);
            if (r1 != r0) {
                ai[r1] = r0;
            }
        }
    };

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        area ca(n);
        for (const auto& as: allowedSwaps) {
            ca.connect(as[0], as[1]);
        }
        std::unordered_map<int, std::unordered_map<int, int>> shms;
        std::unordered_map<int, std::unordered_map<int, int>> thms;
        for (int p=0; p<n; ++p) {
            int pr = ca.getroot(p);
            auto& shm = shms[pr];
            shm[source[p]]++;
            auto& thm = thms[pr];
            thm[target[p]]++;
        }
        int m = 0;
        for (const auto& [sk, shm]: shms) {
            auto& thm = thms[sk];
            for (const auto& [k, c]: shm) {
                m += std::min(c, thm[k]);
            }
        }
        return n - m;
    }
};
