class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
	std::vector<std::tuple<int, long long, int>> ya;
	long long totalArea = 0;
	std::vector<int> xbs;
	std::vector<std::tuple<int, int, int>> yscan;
	for (int p=0; p<squares.size(); p++) {
	    auto& sq = squares[p];
	    xbs.push_back(sq[0]);
	    xbs.push_back(sq[0]+sq[2]);
	    yscan.emplace_back(sq[1], p, 1);
	    yscan.emplace_back(sq[1]+sq[2], p, -1);
	}
	std::sort(xbs.begin(), xbs.end());
	xbs.erase(std::unique(xbs.begin(), xbs.end()), xbs.end());
	int xbss = xbs.size();
	std::vector<int> xac(xbss-1, 0);
	std::vector<int> diff(xbss);
	std::sort(yscan.begin(), yscan.end());
	for (int yp=0; yp<yscan.size()-1; ) {
	    int ype = yp;
	    while (ype<yscan.size()-1 && std::get<0>(yscan[ype])==std::get<0>(yscan[yp])) {
		ype++;
	    }
	    fill(diff.begin(), diff.end(), 0);
	    for (int cyp=yp; cyp<ype; cyp++) {
		auto&& [_, id, pm] = yscan[cyp];
		int xl = squares[id][0];
		int xr = squares[id][0] + squares[id][2];
		int l = lower_bound(xbs.begin(), xbs.end(), xl) - xbs.begin();
                int r = upper_bound(xbs.begin(), xbs.end(), xr) - xbs.begin();
		diff[l] += pm;
		diff[r-1] -= pm;
	    }
	    int delta = 0;
            for (int xa = 0; xa < xbss-1; xa++) {
                delta += diff[xa];
                xac[xa] += delta;
            }
	    int xlen = 0;
	    for (int xa=0; xa<xbss-1; xa++) {
		if (xac[xa] > 0) {
		    xlen += xbs[xa+1]-xbs[xa];
		}
	    }
	    totalArea += static_cast<long long>(xlen) * (std::get<0>(yscan[ype]) - std::get<0>(yscan[yp]));
	    ya.emplace_back(std::get<0>(yscan[ype]), totalArea, xlen);
	    yp = ype;
	}
	for (int p=0; p<ya.size(); p++) {
	    auto& [y, a, xl] = ya[p];
	    if (a * 2 >= totalArea) {
		return static_cast<double>(y)-(2*a-totalArea)/(2.0*xl);
	    }
	}
	return -1.0;
    }
};
