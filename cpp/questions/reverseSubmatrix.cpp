#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rs = grid.size();
	int cs = grid[0].size();
	int u = x;
	int d = x + k - 1;
	int l = y;
	int r = y + k;
	while (u < d) {
	    std::swap_ranges(grid[u].begin()+l, grid[u].begin()+r, grid[d].begin()+l);
	    ++u;
	    --d;
	}
	return grid;
    }
};
