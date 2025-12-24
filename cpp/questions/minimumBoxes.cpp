class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = std::accumulate(apple.begin(), apple.end(), 0);
        std::sort(capacity.begin(), capacity.end(), [](const int a, const int b){
            return a > b;
        });
        int ans = 0;
        for (int c : capacity) {
            apples -= c;
            ans += 1;
            if (apples <= 0) {
                return ans;
            }
        }
        return -1;
    }
};
