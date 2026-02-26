class Solution {
public:
    int numSteps(string s) {
        int ss = s.size();
        int ans = ss-1;
        int carry = 0;
        for (int p=ss-1; p>0; --p) {
            int sum = s[p]-'0' + carry;
            int s1 = sum % 2;
            ans += s1;
            carry = (sum + s1) / 2;
        }
        return ans+carry;
    }
};
