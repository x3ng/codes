#include <string>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int ns = nums.size();
        std::vector<bool> fg(1<<ns, false);
        int dn = 0;
        for (const auto& n: nums) {
            fg[std::stoi(n, nullptr, 2)] = true;
            while (fg[dn]) {
                ++dn;
            }
        }
        return std::bitset<32>(dn).to_string().substr(32-ns, ns);
    }
};
