#include <string>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
	int m = str2.size();
	std::string tmp(n+m-1, '\0');
	for (int p=0; p<n; ++p) {
	    if (str1[p] == 'T') {
		for (int rp=0; rp<m; ++rp) {
		    char& cc = tmp[p+rp];
		    if (cc == '\0') {
			cc = str2[rp];
		    } else if (cc != str2[rp]) {
			return "";
		    }
		}
	    }
	}
	std::string tmpp = tmp;
	for (auto& c: tmpp) {
	    c = c=='\0' ? 'a' : c;
	}
	for (int p=0; p<n; ++p) {
	    if (str1[p] == 'F') {
		bool cf = true;
		std::string ccs = tmpp.substr(p, m);
		cf = ccs == str2;
		for (int rp=m-1; rp>=0&&cf; --rp) {
		    if (tmpp[p+rp] != str2[rp]) {
			break;
		    } else if (tmp[p+rp] == '\0') {
			tmpp[p+rp] = 'b';
			cf = false;
		    }
		}
		if (cf) {
		    return "";
		}
	    }
	}
	return tmpp;
    }
};
