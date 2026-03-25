#include <vector>

using namespace std;

class Solution {
private:
    bool vc(const std::vector<long long>& v, const long long& t) {
	int l = 0;
	int r = v.size() - 1;
	while (l < r) {
	    int m = (l + r) / 2;
	    if (v[m] == t) {
		return true;
	    } else if (v[m] > t) {
		r = m - 1;
	    } else {
		l = m + 1;
	    }
	}
	return v[l] == t;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int gr = grid.size();
        int gc = grid[0].size();
	std::vector<long long> hp(gr);
	std::vector<long long> vp(gc);
	for (int r=0; r<gr; ++r) {
	    long long rs = 0;
	    for (int c=0; c<gc; ++c) {
		rs += grid[r][c];
		vp[c] += rs;
	    }
	    hp[r] = vp[gc-1];
	}
	if (vp[gc-1] % 2) {
	    return false;
	}
	long long tgt = vp[gc-1] / 2;
	return vc(vp, tgt) || vc(hp, tgt);
    }
};
