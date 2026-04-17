#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int reverse(int n) {
        while (n && n%10 == 0) {
            n /= 10;
        }
        int r = 0;
        while (n) {
            r = r*10 + n % 10;
            n /= 10;
        }
        return r;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> hm; 
        int ans = n;
        for (int p=n-1; p>=0; --p) {
            const int rn = reverse(nums[p]);
            if (hm.find(rn) != hm.end()) {
                ans = std::min(ans, hm[rn]-p);
            }
            hm[nums[p]] = p;
        }
        return ans==n ? -1 : ans;
    }
};
