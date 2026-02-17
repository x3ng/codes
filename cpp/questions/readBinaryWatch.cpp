class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> ans;
        for (int h=0; h<12; h++) {
            int hc = __builtin_popcount(h);
            int rm = turnedOn - hc;
            if (rm < 0) {
                continue;
            }
            for (int m=0; m<60; m++) {
                int mc = __builtin_popcount(m);
                if (mc == rm) {
                    ans.push_back(std::to_string(h) + ":" + (m < 10 ? "0" : "") + std::to_string(m));
                }
            }
        }
        return ans;
    }
};
