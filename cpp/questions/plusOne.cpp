class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int p=digits.size()-1; p>=0; p--) {
            if (digits[p] < 9) {
                digits[p]++;
                return digits;
            } else {
                digits[p] = 0;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
