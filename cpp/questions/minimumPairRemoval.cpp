class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        std::vector<int> nps(n);
        for (int p=0; p<n-1; p++) {
            nps[p] = p+1;
        }
        while (1) {
            int cp = nps[n-1];
            int np = nps[cp];
            int mps = nums[cp] + nums[np];
            int mp = cp;
            bool flag = true;
            while (np != 0) {
                if (nums[np] < nums[cp]) {
                    flag = false;
                }
                int cs = nums[cp] + nums[np];
                if (cs < mps) {
                    mp = cp;
                    mps = cs;
                }
                cp = np;
                np = nps[cp];
            }
            if (flag) {
                return ans;
            }
            nums[mp] = mps;
            nps[mp] = nps[nps[mp]];
            ans++;
        }
        return ans;
    }
};
