#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::vector<std::vector<int>> ans;
        int mad = INT_MAX;
        for (int p=1; p<arr.size(); p++) {
            const int curd = arr[p] - arr[p-1];
            if (curd > mad) {
                continue;
            } else if (curd == mad) {
                ans.push_back(std::vector<int>{arr[p-1], arr[p]});
            } else {
                ans.clear();
                ans.push_back(std::vector<int>{arr[p-1], arr[p]});
                mad = curd;
            }
        }
        return ans;
    }
};
