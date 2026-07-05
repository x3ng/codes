#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::greater<>> gq;
    std::priority_queue<int, std::vector<int>, std::less<>> lq;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (lq.size() <= gq.size()) {
            lq.push(num);
        } else {
            gq.push(num);
        }
        if (lq.empty() || gq.empty()) {
            return;
        }
        while (lq.top() > gq.top()) {
            int lt = lq.top();
            int gt = gq.top();
            lq.pop();
            gq.pop();
            lq.push(gt);
            gq.push(lt);
        }
    }
    
    double findMedian() {
        if (lq.size() == gq.size()) {
            return (lq.top()+gq.top()) / 2.0;
        } else {
            return static_cast<double>(lq.top());
        }
    }
};
