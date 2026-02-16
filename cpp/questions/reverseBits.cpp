class Solution {
private:
    const uint32_t r1 = 0x55555555;
    const uint32_t r2 = 0x33333333;
    const uint32_t r4 = 0x0f0f0f0f;
    const uint32_t r8 = 0x00ff00ff;
public:
    int reverseBits(int n) {
        uint32_t m = static_cast<uint32_t>(n);
        m = m >> 1 & r1 | (m & r1) << 1;               
        m = m >> 2 & r2 | (m & r2) << 2;
        m = m >> 4 & r4 | (m & r4) << 4;
        m = m >> 8 & r8 | (m & r8) << 8;
        m = m >> 16 | m << 16;
        return m;
    }
};
