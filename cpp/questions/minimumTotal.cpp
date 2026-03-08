#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ts = triangle.size();
        int ans = INT_MAX;
        for (int li=1; li<ts; ++li) {
            triangle[li][0] += triangle[li-1][0];
            for (int lp=1; lp<li; ++lp) {
                triangle[li][lp] += std::min(triangle[li-1][lp-1], triangle[li-1][lp]);
                ans = li==ts-1 ? std::min(ans, triangle[li][lp]) : ans;
            }
            triangle[li][li] += triangle[li-1][li-1];
        }
        return std::min(ans, std::min(triangle[ts-1][0], triangle[ts-1][ts-1]));
    }
};
