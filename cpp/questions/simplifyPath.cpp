class Solution {
public:
    string simplifyPath(string path) {
      std::vector<std::string> stk;
      istringstream ss(path);
      std::string s;
      while (getline(ss, s, '/')) {
        if (s.empty() || s == ".") {
          continue;
        } else if (s != "..") {
          stk.push_back(s);
        } else if (!stk.empty()) {
          stk.pop_back();
        }                 
      }
      std::string ans;
      for (std::string& s : stk) {
        ans += '/';
        ans += s;
      }
      return stk.empty() ? "/" : ans;
    }
};
