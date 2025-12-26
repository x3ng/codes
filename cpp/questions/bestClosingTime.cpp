class Solution {
public:
    int bestClosingTime(std::string customers) {
        std::vector<std::pair<int, int>> nm;
        int n = customers.size();
        int yc = 0;
        int nc = 0;
        int minc = 0;
        int ans = -1;
        for (int p=0; p<n; p++) {
            if (customers[p] == 'N') {
                nc++;
            } else {
                yc--;
            }
            if (minc > nc + yc) {
                minc = nc + yc;
                ans = p;
            }
        }
        return ans==-1 ? 0 : ans+1;;
    }
};
