#include <queue>

class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::less<>> shq;
    std::priority_queue<int, std::vector<int>, std::greater<>> bhq;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        shq.push(num);
        while (shq.size()-bhq.size() > 1) {
            bhq.push(shq.top());
            shq.pop();
        }
        while (!bhq.empty() && shq.top()>bhq.top()) {
            bhq.push(shq.top());
            shq.push(bhq.top());
            bhq.pop();
            shq.pop();
        }
    }
    
    double findMedian() {
        if (shq.size() == bhq.size()) {
            return (shq.top() + bhq.top()) / 2.0;
        } else {
            return shq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
