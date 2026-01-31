#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size() - 1;
        if (letters[0] > target || letters[r] <= target) {
            return letters[0];
        }
        while (l < r) {
            int m = (l + r) / 2;
            if (letters[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return letters[l];
    }
};
