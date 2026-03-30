#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
	if (n != s2.size()) {
	    return false;
	}
	std::array<std::array<int, 26>, 2> hm1{};
	std::array<std::array<int, 26>, 2> hm2{};
	for (int p=0; p<n; ++p) {
	    hm1[p&1][s1[p]-'a'] += 1;
	    hm2[p&1][s2[p]-'a'] += 1;
	}
	return hm1 == hm2;
    }
};
