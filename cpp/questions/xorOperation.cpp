class Solution {
public:
    int xorOperation(int n, int start) {
      int ans = 0;
      for (int i=start; i<start+n*2; i+=2) {
        ans ^= i;
      }
      return ans;
    }
};
