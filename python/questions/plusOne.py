class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for p in range(len(digits)-1, -1, -1):
            if digits[p] < 9:
                digits[p] += 1
                return digits
            else:
                digits[p] = 0
        digits.append(0)
        digits[0] = 1
        return digits
