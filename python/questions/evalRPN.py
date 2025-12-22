class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for token in tokens:
            if token == "+" or token == "-" or token == "*" or token == "/":
                num = st.pop()
                if token == "+":
                    st[-1] += num
                elif token == "-":
                    st[-1] -= num
                elif token == "*":
                    st[-1] *= num
                elif token == "/":
                    st[-1] = trunc(st[-1]/num)
                else:
                    st[-1] = st[-1]
            else:
                st.append(int(token))
        return st[-1]
