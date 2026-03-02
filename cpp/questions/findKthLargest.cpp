#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<>> pq;
        for (int p=0; p<nums.size(); ++p) {
            int cn = nums[p];
            if (pq.size() < k) {
                pq.push(cn);
            } else if (cn > pq.top()) {
                pq.pop();
                pq.push(cn);
            }
        }
        return pq.top();
    }
};
