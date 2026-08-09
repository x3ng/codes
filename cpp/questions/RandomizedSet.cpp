#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
private:
    std::unordered_map<int, int> hm;
    std::vector<int> v;
public:
    RandomizedSet() { }
    
    bool insert(int val) {
        auto it = hm.find(val);
        if (it == hm.end()) {
            hm[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = hm.find(val);
        if (it != hm.end()) {
            v[it->second] = v.back();
            hm[v.back()] = it->second;
            v.pop_back();
            hm.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, v.size()-1);
        return v[dist(gen)];
    }
};
