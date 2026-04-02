#include <vector>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
	int cr = coins.size();
	int cc = coins[0].size();
	std::vector<std::vector<int>> tmp(cc, std::vector<int>(3));
	tmp[0] = {coins[0][0], std::max(coins[0][0], 0), std::max(coins[0][0], 0)};
	for (int c=1; c<cc; ++c) {
	    const int& cv = coins[0][c];
	    tmp[c][0] = tmp[c-1][0] + cv;
	    tmp[c][1] = std::max(tmp[c-1][1]+cv, tmp[c-1][0]);
	    tmp[c][2] = std::max(tmp[c-1][2]+cv, tmp[c-1][1]);
	}
	for (int r=1; r<cr; ++r) {
	    int cv = coins[r][0];
	    auto ps = tmp[0];
	    tmp[0][0] += cv;
	    tmp[0][1] = std::max(ps[1]+cv, ps[0]);
	    tmp[0][2] = std::max(ps[2]+cv, ps[1]);
	    for (int c=1; c<cc; ++c) {
		cv = coins[r][c];
		ps = tmp[c];
		tmp[c][0] = std::max(tmp[c-1][0]+cv, ps[0]+cv);
		tmp[c][1] = std::max(std::max(ps[1]+cv, ps[0]), std::max(tmp[c-1][1]+cv, tmp[c-1][0]));
		tmp[c][2] = std::max(std::max(ps[2]+cv, ps[1]), std::max(tmp[c-1][2]+cv, tmp[c-1][1]));
	    }
	}
	return std::max(std::max(tmp[cc-1][0], tmp[cc-1][1]), tmp[cc-1][2]);
    }
};
