class Solution {
private:
    static constexpr int MOD = 1e9+7;
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
	int rs = rectangles.size();
	std::vector<int> ybs;
	std::vector<std::tuple<int, int, int>> xmm;
	for (int p=0; p<rs; p++) {
	    auto& rec = rectangles[p];
	    ybs.push_back(rec[1]);
	    ybs.push_back(rec[3]);
	    xmm.emplace_back(rec[0], p, 1);
	    xmm.emplace_back(rec[2], p, -1);
	}
	std::sort(ybs.begin(), ybs.end());
	std::sort(xmm.begin(), xmm.end());
	ybs.erase(std::unique(ybs.begin(), ybs.end()), ybs.end());
	int ybss = ybs.size();
	std::vector<int> ycs(ybss-1, 0);
	long long ans = 0;
	for (int p=0; p<xmm.size()-1; ) {
	    int pe = p;
	    while (pe+1<xmm.size() && std::get<0>(xmm[pe])==std::get<0>(xmm[p])) {
		pe++;
	    }
	    for (int sp=p; sp<pe; sp++) {
		auto&& [_, id, pm] = xmm[sp];
		int yu = rectangles[id][3];
		int yd = rectangles[id][1];
		for (int ys=1; ys<ybss; ys++) {
		    if (yu >= ybs[ys] && yd <= ybs[ys-1]) {
			ycs[ys-1] += pm;
		    }
		}
	    }
	    int ylen = 0;
	    for (int ys=0; ys<ybss-1; ys++) {
		if (ycs[ys] > 0) {
		    ylen += ybs[ys+1] - ybs[ys]; 
		}
	    }
	    ans += static_cast<long long>(ylen) * (std::get<0>(xmm[pe])-std::get<0>(xmm[p]));
	    p = pe;
	}
	return ans % MOD;
    }
};
