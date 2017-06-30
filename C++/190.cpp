class Solution {
    static constexpr uint32_t mask[5][2] = {
        0xFFFF0000, 0x0000FFFF,
        0xFF00FF00, 0x00FF00FF,
        0xF0F0F0F0, 0x0F0F0F0F,
        0xCCCCCCCC, 0x33333333,
        0xAAAAAAAA, 0x55555555
    };
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n&mask[1][0]) >> 8) | ((n&mask[1][1]) << 8);
        n = ((n&mask[2][0]) >> 4) | ((n&mask[2][1]) << 4);
        n = ((n&mask[3][0]) >> 2) | ((n&mask[3][1]) << 2);
        n = ((n&mask[4][0]) >> 1) | ((n&mask[4][1]) << 1);
        return n;
    }
};
