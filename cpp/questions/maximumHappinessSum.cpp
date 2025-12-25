class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // std::sort(happiness.begin(), happiness.end(), [](const int& a, const int& b) {
        //     return a > b;
        // });
        // long long ans = happiness[0];
        // for (int p=1; p<k; p++) {
        //     if (happiness[p] > p) {
        //         ans += happiness[p] - p;
        //     } else {
        //         return ans;
        //     }
        // }
        // return ans;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
        long long reduce = (static_cast <long long>(k)*(k-1))/2;
        int cnt = 0;
        long long ans = 0;
        while (cnt < k) {
            minHeap.push(cnt);
            cnt++;
        }
        for (int& h : happiness) {
            if (h > minHeap.top()) {
                minHeap.pop();
                minHeap.push(h);
            }
        }
        while (cnt > 0) {
            cnt--;
            ans += minHeap.top();
            minHeap.pop();
        }
        return ans - reduce;
    }
};
