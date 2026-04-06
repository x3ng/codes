#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

class Solution {
private:
    static constexpr std::array<std::array<int, 2>, 4> dirs = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
	int y = 0;
	int d = 0;
	int ans = 0;
	std::unordered_set<long long> hs;
	hs.reserve(obstacles.size());
	for (const auto& o: obstacles) {
	    hs.insert(static_cast<unsigned long long>(o[0])<<32 | static_cast<unsigned int>(o[1]));
	}
	for (auto& c: commands) {
	    if (c == -2) {
		d = (d + 3) % 4;
	    } else if (c == -1) {
		d = (d + 1) % 4;
	    } else {
		while (c > 0) {
		    x += dirs[d][0];
		    y += dirs[d][1];
		    --c;
		    if (hs.find(static_cast<unsigned long long>(x)<<32 | static_cast<unsigned int>(y)) != hs.end()) {
			x -= dirs[d][0];
			y -= dirs[d][1];
			break;
		    }
		}
	    }
	    ans = std::max(ans, x*x+y*y);
	}
	return ans;
    }
};
