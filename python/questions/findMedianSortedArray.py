from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        p1 = 0
        p2 = 0
        r1 = len(nums1)
        r2 = len(nums2)
        ls = r1 + r2
        hl = (ls + 1) // 2
        ds = hl + 1
        while ds>1:
            if p1 == r1:
                p2 = hl - r1
                break
            elif p2 == r2:
                p1 = hl - r2
                break
            np = ds // 2
            n1 = p1 + np
            n2 = p2 + np
            n1 = min(n1, r1)
            n2 = min(n2, r2)
            if nums1[n1-1] > nums2[n2-1]:
                p2 = n2
                ds -= np
            else:
                p1 = n1
                ds -= np
        nv1 = nums1[p1] if p1<r1 else float("inf")
        nv2 = nums2[p2] if p2<r2 else float("inf")
        pv1 = nums1[p1-1] if p1>0 else -float("inf")
        pv2 = nums2[p2-1] if p2>0 else -float("inf")
        if ls % 2:
            return max(pv1, pv2)
        else:
            return (max(pv1, pv2) + min(nv1, nv2)) / 2
