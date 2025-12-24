class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        apples = sum(apple)
        capacity.sort(reverse=True)
        ans = 0;
        for c in capacity:
            apples -= c
            ans += 1
            if apples <= 0:
                return ans
        return -1
