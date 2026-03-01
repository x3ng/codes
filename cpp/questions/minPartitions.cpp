class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (const auto& c: n) {
            ans = std::max(ans, c-'0');
        }
        return ans;
    }
};
