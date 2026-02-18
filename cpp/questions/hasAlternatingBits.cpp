class Solution {
public:
    bool hasAlternatingBits(int n) {
        long t = n ^ (n >> 1);
        return !(t & t+1);
    }
};
