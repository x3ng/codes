#include <vector>

using namespace std;

class Fancy {
private:
    static constexpr int MOD = 1e9 + 7;
    std::vector<std::pair<int, int>> ele;
    std::vector<std::pair<int, int>> mod;
public:
    Fancy() {
    }
    
    void append(int val) {
        ele.emplace_back(mod.size(), val);
    }
    
    void addAll(int inc) {
        mod.emplace_back(0, inc); 
    }
    
    void multAll(int m) {
        mod.emplace_back(1, m); 
    }
    
    int getIndex(int idx) {
        if (idx >= ele.size()) {
            return -1;
        }
        int sl = ele[idx].first;
        long long sv = ele[idx].second;
        int ms = mod.size();
        while (sl < ms) {
            const auto& [w, n] = mod[sl];
            if (w) {
                sv *= n;
            } else {
                sv += n;
            }
            sv %= MOD;
            ++sl;
        }
        ele[idx] = {sl, sv};
        return sv;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
