class Solution {
public:
    bool isValid(string s) {
      std::unordered_map<char, char> mp{{'(', ')'}, {'[', ']'}, {'{', '}'}};
      std::stack<char> st;
      st.push('!');
      for (char c : s) {
        if (mp.find(c) != mp.end()) {
          st.push(c);
        } else {
          if (mp[st.top()] != c) {
            return 0;
          }
          st.pop();
        }
      }
      return st.size() == 1;
    }
};
