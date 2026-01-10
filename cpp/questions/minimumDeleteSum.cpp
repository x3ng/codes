class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int s1s = s1.size();
        int s2s = s2.size();
        int all_reduce = reduce(s1.begin(), s1.end(), 0) + reduce(s2.begin(), s2.end(), 0);
        std::vector<int> rs(s1s+1, 0);
        int pre;
        int tmp;
        for (int p2=0; p2<s2s; p2++) {
            pre = 0;
            for (int p1=0; p1<s1s; p1++) {
                if (s1[p1] == s2[p2]) {
                    tmp = pre + s1[p1];
                } else {
                    tmp = std::max(rs[p1+1], rs[p1]);
                }
                pre = rs[p1+1];
                rs[p1+1] = tmp;
            }
        }
        return all_reduce-rs[s1s]*2;
    }
};
