#include <vector>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int mr = mat.size();
	int mc = mat[0].size();
	k %= mc;
	if (k == 0) {
	    return true;
	}
	for (int r=0; r<mr; r+=2) {
	    for (int c=0; c<mc; ++c) {
		if (mat[r][c] != mat[r][(c+k)%mc]) {
		    return false;
		}
	    }
	}
	for (int r=1; r<mr; r+=2) {
	    for (int c=0; c<mc; ++c) {
		if (mat[r][c] != mat[r][(mc+c-k)%mc]) {
		    return false;
		}
	    }
	}
	return true;
    }
};
