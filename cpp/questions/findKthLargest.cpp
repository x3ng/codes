#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<>> pq;        
        for (const auto n: nums) {
            if (pq.size() < k) {
                pq.push(n);
            } else if (n > pq.top()) {
                pq.pop();
                pq.push(n);
            }
        }
        return pq.top();
    }
};
