class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        std::string tmp = "";
        auto bt = [&](this auto&& bt, int lc, int rc) -> void {
            if (lc==n && rc==n) {
                ans.emplace_back(tmp);
            } else if (lc<=n && rc<=lc) {
                tmp += '(';
                bt(lc+1, rc);
                tmp.pop_back();
                tmp += ')';
                bt(lc, rc+1);
                tmp.pop_back();
            }
        };
        bt(0, 0);
        return ans;
    }
};
