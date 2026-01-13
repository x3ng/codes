class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long ta = 0;
        std::map<int, long long> ew;
        for (auto& square : squares) {
            ta += 1LL * square[2] * square[2];
            ew[square[1]] += square[2];
            ew[square[1]+square[2]] -= square[2];
        }
        long long ca = 0;
        int csw = 0;
        for (auto cs=ew.begin(); ;) {
            auto [cy, cw] = *cs;
            csw += cw;
            int ny = (++cs)->first;
            ca += 1LL * (ny-cy) * csw;
            if (ca*2 >= ta) {
                return ny-(ca*2-ta)/(csw*2.0);
            }
        }
    }
};
