#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int rs = rowCosts.size();
	int cs = colCosts.size();
	int rd = startPos[0] > homePos[0] ? -1 : 1;
	int cd = startPos[1] > homePos[1] ? -1 : 1;
	int ans = 0;
	for (int sr=startPos[0]+rd; sr!=homePos[0]+rd; sr+=rd) {
	    ans += rowCosts[sr];
	}
	for (int sc=startPos[1]+cd; sc!=homePos[1]+cd; sc+=cd) {
	    ans += colCosts[sc];
	}
	return ans;
    }
};
