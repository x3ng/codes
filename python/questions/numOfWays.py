class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        lineType = []
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    if i==j or j==k:
                        continue
                    lineType.append(i*100+j*10+k)
        lt = len(lineType)
        nextLine = [[0 for _ in range(lt)] for _ in range(lt)]
        for i in range(lt):
            rb3 = lineType[i] % 10
            rb2 = lineType[i] // 10 % 10
            rb1 = lineType[i] // 100
            for j in range(lt):
                cb3 = lineType[j] % 10
                cb2 = lineType[j] // 10 % 10
                cb1 = lineType[j] // 100
                if rb3!=cb3 and rb2!=cb2 and rb1!=cb1:
                    nextLine[i][j] = 1
        fullMap = [[0 for _ in range(lt)] for _ in range(n+1)]
        for p in range(lt):
            fullMap[1][p] = 1
        for r in range(1, n+1):
            for pr in range(lt):
                for cr in range(lt):
                    if nextLine[pr][cr] == 1:
                        fullMap[r][cr] += fullMap[r-1][pr]
                        fullMap[r][cr] %= MOD
        print(fullMap)
        return sum(fullMap[n])%MOD

if __name__ == "__main__":
    test = Solution()
    print(test.numOfWays(2))
