#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        std::set<std::pair<int, int>> area;
        for (int p=1; p<=1+dist; p++) {
            area.insert({nums[p], p});
        }
        auto it = area.begin();
        long long curs = nums[0];
        for (int p=0; p<k-1; p++) {
            curs += it->first;
            it++;
        }
        it--;
        long long ans = curs;
        for (int p=2+dist; p<nums.size(); p++) {
            std::pair<int, int> ie = {nums[p], p};
            std::pair<int, int> de = {nums[p-dist-1], p-dist-1};
            area.insert(ie);
            if (ie.first < it->first) {
                curs += ie.first - (it--)->first;
            }
            if (de.first <= it->first) {
                curs += (++it)->first - de.first;
            }
            area.erase(de);
            ans = std::min(ans, curs);
        }
        return ans;
    }
};
