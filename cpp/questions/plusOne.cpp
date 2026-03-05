#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int p=digits.size()-1; p>=0; p--) {
            auto& d = digits[p];
            if (++d == 10) {
                d = 0;
            } else {
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
