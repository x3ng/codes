#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        std::vector<std::pair<int, int>> pj;
        pj.reserve(n);
        for (int p=0; p<n; ++p) {
            pj.emplace_back(capital[p], profits[p]);
        }
        std::sort(pj.begin(), pj.end());
        std::priority_queue<int, std::vector<int>, std::less<>> phq;
        int p = 0;
        while (k--) {
            while (p < n && w >= pj[p].first) {
                phq.push(pj[p].second);
                ++p;
            }
            if (phq.empty()) {
                break;
            } else {
                w += phq.top();
                phq.pop();
            }
        }
        return w;
    }
};
