class Solution {
public:
    string addBinary(string a, string b) {
        const std::string& ls = a.size() > b.size() ? a : b;
        const std::string& ss = a.size() > b.size() ? b : a;
        int lsp = ls.size() - 1;
        int ssp = ss.size() - 1;
        std::string ans(lsp+1, '0');
        int p = lsp;
        bool c = false;
        while (ssp >= 0) {
            bool cl = ls[lsp--] == '1';
            bool cs = ss[ssp--] == '1';
            ans[p--] = cl ^ cs ^ c ? '1' : '0';
            c = cl&cs | cl&c | cs&c;
        }
        while (lsp >= 0) {
            bool cl = ls[lsp--] == '1';
            ans[p--] = cl ^ c ? '1' : '0';
            c = cl & c;
        }
        return c ? "1"+ans : ans;
    }
};
