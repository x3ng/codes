class Solution {
private:
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int n=2; n*n<=num; n++) {
            if (num % n == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int num=left; num<=right; num++) {
           ans += isPrime(__builtin_popcount(num));
        }
        return ans;
    }
};
