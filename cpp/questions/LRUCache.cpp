class LRUCache {
private:
    std::unordered_map<int, std::pair<int, int>> hvm;
    std::queue<int> kq;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = hvm.find(key);
        if (it != hvm.end()) {
            put(key, it->second.second);
            return hvm[key].second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (hvm.find(key) != hvm.end()) {
            hvm[key].first += 1;
            hvm[key].second = value;
            cap++;
            kq.push(key);
            return;
        }
        while (kq.size() == cap) {
            int dk = kq.front();
            if (hvm[dk].first == 1) {
                hvm.erase(dk);
            } else {
                hvm[dk].first--;
                cap--;
            }
            kq.pop();
        }
        kq.push(key);
        hvm[key] = {1, value};
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
