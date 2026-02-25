class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [](int a, int b) -> bool {
            int ac = __builtin_popcount(a);
            int bc = __builtin_popcount(b);
            if (ac < bc) {
                return true;
            }
            if (bc < ac) {
                return false;
            }
            return a < b;
        };
        std::sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
