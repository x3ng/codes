class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) {
            return false;
        }
        int sn = stoi(s.substr(0, k), nullptr, 2); 
        std::unordered_set<int> sns = {sn};
        for (int p=0; p+k<s.size(); p++) {
            sn = ((sn - (s[p]=='1' ? 1 << (k-1) : 0)) << 1) + (s[p+k]=='1');
            sns.insert(sn);
        }
        return sns.size() == 1<<k;
    }
};
