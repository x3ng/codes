#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> ans;
        ans.reserve(n-k+1);
        std::deque<int> dq;
        for (int i=0; i<n; ++i) {
            const int ni = nums[i];
            while (!dq.empty() && dq.front()<=i-k) {
                dq.pop_front();
            }
            while (!dq.empty() && ni>=nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
