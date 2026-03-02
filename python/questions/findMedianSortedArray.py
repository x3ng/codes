class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        ns1 = len(nums1)
        ns2 = len(nums2)
        a = ns1 + ns2
        t = a // 2
        l = 0
        r = ns1
        while l <= r:
            m = (l + r) // 2
            tm = t - m
            n1l = nums1[m-1] if m > 0 else -inf
            n1h = nums1[m] if m < ns1 else inf
            n2l = nums2[tm-1] if tm > 0 else -inf
            n2h = nums2[tm] if tm < ns2 else inf
            if n1l <= n2h and n2l <= n1h:
                if a % 2:
                    return min(n1h, n2h)
                else:
                    return (max(n1l, n2l) + min(n1h, n2h)) / 2
            elif n1l > n2h:
                r = m - 1
            else:
                l = m + 1
        return 0
