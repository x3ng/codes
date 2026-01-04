class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def fourDivisorsSum(num: int) -> int:
            if num < 6:
                return 0
            sqrt_num = int(num**0.5)
            if sqrt_num * sqrt_num == num:
                return 0
            sum = 1+num
            for n in range(2, sqrt_num+1):
                if num % n == 0:
                    if sum != 1+num:
                        return 0
                    sum += n+num//n
            if sum == 1+num:
                return 0
            return sum
        csd = {}
        ans = 0
        for num in nums:
            if csd.get(num, -1) == -1:
                csd[num] = fourDivisorsSum(num)
                ans += csd[num]
            else:
                ans += csd[num]
        return ans
