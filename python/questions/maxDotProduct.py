class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        len1 = len(nums1)
        len2 = len(nums2)
        mm = [ 0 for _ in range(len2)]
        mm[0] = nums1[0] * nums2[0]
        for p2 in range(1, len2):
            tmp = nums1[0] * nums2[p2]
            tmp = max(tmp, mm[p2-1])
            mm[p2] = tmp
        ans = mm[len2-1]
        for p1 in range(1, len1):
            tmp = nums1[p1] * nums2[0]
            pre = mm[0]
            mm[0] = max(tmp, mm[0])
            for p2 in range(1, len2):
                tmp = nums1[p1] * nums2[p2]
                tmp += pre if pre>0 else 0
                tmp = max(tmp, mm[p2-1])
                pre = mm[p2]
                mm[p2] = max(tmp, mm[p2])
            ans = max(ans, mm[len2-1])
        return ans

