#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int gr = grid.size();
	int gc = grid[0].size();
	std::vector<std::vector<long long>> f(gc, std::vector<long long>(2, 1));
	f[0] = {grid[0][0], grid[0][0]};
	for (int c=1; c<gc; ++c) {
	    f[c][0] = f[c-1][0] * grid[0][c];
	    f[c][1] = f[c-1][0] * grid[0][c];
	    if (f[c][0] > f[c][1]) {
		std::swap(f[c][0], f[c][1]);
	    }
	}
	for (int r=1; r<gr; ++r) {
	    f[0][0] *= grid[r][0];
	    f[0][1] *= grid[r][0];
	    if (f[0][0] > f[0][1]) {
		std::swap(f[0][0], f[0][1]);
	    }
	    for (int c=1; c<gc; ++c) {
		const auto& cv = grid[r][c];
		const auto cmin = std::min(f[c-1][0], f[c][0]);
		const auto cmax = std::max(f[c-1][1], f[c][1]);
		if (cv > 0) {
		    f[c][0] = cmin * cv;
		    f[c][1] = cmax * cv;
		} else {
		    f[c][0] = cmax * cv;
		    f[c][1] = cmin * cv;
		}
	    }
	}
	return f[gc-1][1] < 0 ? -1 : f[gc-1][1]%MOD;
    }
};
