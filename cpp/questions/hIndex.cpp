#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cs = citations.size();
        std::vector<int> rc(cs+1, 0);
        for (const auto& c: citations) {
            if (c >= cs) {
                rc[cs] += 1;
            } else {
                rc[c] += 1;
            }
        }
        int rs = 0;
        for (int p=cs; p>=0; --p) {
            rs += rc[p];
            if (rs >= p) {
                return p;
            }
        }
        return 0;
    }
};
