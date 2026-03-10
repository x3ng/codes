#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        std::vector<int> buy(k + 1, INT_MIN);
        std::vector<int> sel(k + 1, 0);
        for (const int &price : prices) {
            for (int p = 1; p <= k; ++p) {
                buy[p] = std::max(buy[p], sel[p - 1] - price);
                sel[p] = std::max(sel[p], buy[p] + price);            
            }
        }
        return sel[k];        
    }
};
