#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mm[nums2Size];
    int tmp;
    int pre;
    int ans;
    mm[0] = nums1[0] * nums2[0];
    for (int p2=1; p2<nums2Size; p2++) {
        tmp = nums1[0] * nums2[p2];
        tmp = MAX(tmp, mm[p2-1]);
        mm[p2] = tmp;
    }
    ans = mm[nums2Size-1];
    for (int p1=1; p1<nums1Size; p1++) {
        tmp = nums1[p1] * nums2[0];
        pre = mm[0];
        mm[0] = MAX(pre, tmp);
        for (int p2=1; p2<nums2Size; p2++) {
            tmp = nums1[p1] * nums2[p2];
            tmp += pre>0 ? pre : 0;
            tmp = MAX(tmp, mm[p2-1]);
            pre = mm[p2];
            mm[p2] = MAX(tmp, mm[p2]);
        }
        ans = MAX(ans, mm[nums2Size-1]);
    }
    return ans;
}
