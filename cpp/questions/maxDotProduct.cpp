class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        std::vector<int> mm(len2);
        int tmp;
        int pre;
        tmp = nums1[0] * nums2[0];
        mm[0] = tmp;
        for (int p2=1; p2<len2; p2++) {
            tmp = nums1[0] * nums2[p2];
            mm[p2] = std::max(mm[p2-1], tmp);
        }
        int ans = mm[len2-1];
        for (int p1=1; p1<len1; p1++) {
            tmp = nums2[0] * nums1[p1];
            pre = mm[0];
            mm[0] = std::max(pre, tmp);
            for (int p2=1; p2<len2; p2++) {
                tmp = nums1[p1] * nums2[p2]; 
                tmp += pre>0 ? pre : 0;
                tmp = std::max(mm[p2-1], tmp);
                tmp = std::max(mm[p2], tmp);
                pre = mm[p2];
                mm[p2] = tmp;
            }
            ans = std::max(ans, mm[len2-1]);
        }
        return ans;
    }
};
