#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans;        
        ans.reserve(numRows);
        ans.emplace_back(1, 1);
        for (int i=1; i<numRows; ++i) {
            const auto& pr = ans[i-1];
            std::vector<int> cr(i+1, 1);
            for (int j=1; j<i; ++j) {
                cr[j] = pr[j-1] + pr[j];
            }
            ans.emplace_back(cr);
        }
        return ans;
    }
};
