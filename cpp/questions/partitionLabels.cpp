#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int ss = s.size();
        int fp[26] = {-1};
        std::vector<int> ans;
        for (int i=0; i<ss; ++i) {
            fp[s[i]-'a'] = i;
        }
        int cs = 0;
        while (cs < ss) {
            int ce = fp[s[cs]-'a'];
            for (int j=cs; j<ce+1; ++j) {
                ce = std::max(ce, fp[s[j]-'a']);
            }
            ans.push_back(ce-cs+1);
            cs = ce + 1;
        }
        return ans;
    }
};
