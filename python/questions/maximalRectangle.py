class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        rs = len(matrix)
        cs = len(matrix[0])
        rh = [0 for _ in range(cs)]
        st = [-1]
        ans = 0
        for cr in range(rs):
            for cc in range(cs):
                if matrix[cr][cc] == '1':
                    rh[cc] += 1
                else:
                    rh[cc] = 0
                while len(st)>1 and rh[st[-1]]>=rh[cc]:
                    nh = rh[st[-1]]
                    st.pop()
                    ans = max(ans, nh*(cc-st[-1]-1))
                st.append(cc)
            while len(st)>1 and rh[st[-1]]>=0:
                nh = rh[st[-1]]
                st.pop()
                ans = max(ans, nh*(cs-st[-1]-1))
        return ans
                
