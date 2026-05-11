#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    std::vector<int> ans;
    for (auto p = nums.rbegin(); p != nums.rend(); ++p) {
      int cn = *p;
      while (cn) {
        ans.push_back(cn % 10);
        cn /= 10;
      }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
