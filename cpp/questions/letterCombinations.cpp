class Solution {
private:
    std::map<char, std::string> km = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> ans;
        int dl = digits.size();
        std::string tmp = "";
        auto bt = [&](this auto&& bt, int p, std::string& bs) -> void {
            if (p == dl) {
                ans.push_back(bs);
            }
            for (auto& c: km[digits[p]]) {
                bs.push_back(c);
                bt(p+1, bs);
                bs.pop_back();
            }
        };
        bt(0, tmp);
        return ans;
    }
};
